#include <torch/torch.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "load_data.cpp"
#include "cnn_model.cpp"

// Function to resize image using OpenCV
cv::Mat resize_image(const cv::Mat& img) {
    cv::Mat resized_img;
    cv::resize(img, resized_img, cv::Size(224, 224));
    return resized_img;
}

// Custom transform: Resize image and then convert it to tensor
struct ResizeAndTensorize {
    torch::Tensor operator()(const cv::Mat& img) {
        cv::Mat resized_img = resize_image(img);
        torch::Tensor img_tensor = torch::from_blob(
            resized_img.data, 
            {resized_img.rows, resized_img.cols, 3}, 
            torch::kByte
        );
        img_tensor = img_tensor.permute({2, 0, 1}); // Convert to CxHxW
        return img_tensor.to(torch::kFloat) / 255.0; // Normalize to [0, 1]
    }
};

int main() {
    // Hyperparameters
    const int64_t batch_size = 128;
    const size_t epochs = 10;
    const double learning_rate = 0.01;
    const std::string dataset_path = "dataset/";

    // Load training and validation datasets
    auto train_dataset = ImageFolderDataset<cv::Mat>(dataset_path + "Training", ResizeAndTensorize())
                             .map(torch::data::transforms::Normalize<>(0.485, 0.456, 0.406), {0.229, 0.224, 0.225}))
                             .map(torch::data::transforms::Stack<>());
    auto val_dataset = ImageFolderDataset<cv::Mat>(dataset_path + "Test", ResizeAndTensorize())
                             .map(torch::data::transforms::Normalize<>(0.485, 0.456, 0.406), {0.229, 0.224, 0.225}))
                             .map(torch::data::transforms::Stack<>());

    // Data loaders
    auto train_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(
                            std::move(train_dataset), batch_size);
    auto val_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
                            std::move(val_dataset), batch_size);

    // Model
    CNNModel model;
    torch::Device device(torch::kCPU);
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Training on GPU." << std::endl;
        model->to(torch::kCUDA); // Move model to GPU if available
    }

    // Optimizer
    torch::optim::Adam optimizer(model->parameters(), torch::optim::AdamOptions(learning_rate));

    // Loss function
    torch::nn::CrossEntropyLoss criterion;

    std::vector<double> loss_history;
    
    for (size_t epoch = 1; epoch <= epochs; ++epoch) {
        // Training loop
        model->train();
        float train_loss = 0.0;
        int correct = 0;
        int total = 0;

        for (auto& batch : *train_loader) {
            auto data = batch.data.to(torch::kCUDA);
            auto targets = batch.target.to(torch::kCUDA);

            optimizer.zero_grad(); // reset gradient
            torch::Tensor prediction = model->forward(data); // Execute the model on the input data.
            torch::Tensor loss = torch::nll_loss(prediction, targets); // Compute a loss value to judge the prediction of our model
            loss.backward(); // Compute gradients of the loss
            optimizer.step(); // Update the parameters based on the calculated gradients.

            train_loss += loss.item<float>();
            loss_history.push_back(loss);
            auto predictions = prediction.argmax(1);
            correct += predictions.eq(targets).sum().item<int64_t>();
            total += targets.size(0);
        }

        float accuracy = static_cast<float>(correct) / total;
        std::cout << "Epoch [" << epoch << "/" << epochs << "], "
                  << "Train Loss: " << train_loss / total << ", "
                  << "Accuracy: " << accuracy * 100.0 << "%" << std::endl;

        // Validation loop
        model->eval();
        float val_loss = 0.0;
        correct = 0;
        total = 0;

        for (const auto& batch : *val_loader) {
            auto data = batch.data.to(torch::kCUDA);
            auto targets = batch.target.to(torch::kCUDA);

            torch::Tensor prediction = model->forward(data);
            val_loss += torch::nll_loss(prediction, targets).item<float>();
            auto predictions = prediction.argmax(1);
            correct += predictions.eq(targets).sum().item<int64_t>();
            total += targets.size(0);
        }

        accuracy = static_cast<float>(correct) / total;
        std::cout << "Validation Loss: " << val_loss / total << ", "
                  << "Accuracy: " << accuracy * 100.0 << "%" << std::endl;
    }

    // Save the model
    torch::save(model, "result.pt");

    std::cout << "traning complete!" << std::endl;

    return 0;
}

