#include <torch/torch.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <io.h>
#include <algorithm>
#include <cctype>

using namespace torch;
namespace fs = std::filesystem;

struct CNNModelImpl : torch::nn::Module {
    torch::nn::Conv2d conv1{ nullptr }, conv2{ nullptr }, conv3{ nullptr }, conv4{ nullptr };
    torch::nn::Linear fc1{ nullptr }, fc2{ nullptr }, fc3{ nullptr };
    torch::nn::Dropout dropout;
    torch::nn::ReLU relu;
    torch::nn::MaxPool2d pool{ nullptr };

    CNNModelImpl() {
        // Convolutional layers
        conv1 = register_module("conv1", torch::nn::Conv2d(torch::nn::Conv2dOptions(3, 16, 5).padding(2)));
        conv2 = register_module("conv2", torch::nn::Conv2d(torch::nn::Conv2dOptions(16, 32, 5).padding(2)));
        conv3 = register_module("conv3", torch::nn::Conv2d(torch::nn::Conv2dOptions(32, 64, 5).padding(2)));
        conv4 = register_module("conv4", torch::nn::Conv2d(torch::nn::Conv2dOptions(64, 128, 5).padding(2)));

        fc1 = register_module("fc1", torch::nn::Linear(4608, 1024)); // Change the first parameter to 4608 for 100x100 pixels, 25088 for 224x224
        fc2 = register_module("fc2", torch::nn::Linear(1024, 256));
        fc3 = register_module("fc3", torch::nn::Linear(256, 131)); // Assuming 131 output classes

        // Dropout
        dropout = register_module("dropout", torch::nn::Dropout(0.5));

        // Activation function
        relu = register_module("relu", torch::nn::ReLU());

        // Pooling layer
        pool = register_module("pool", torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2).stride(2)));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = relu(conv1->forward(x));
        std::cout << "conv1 no bugs" << std::endl;
        x = pool->forward(x);
        std::cout << "pool no bugs" << std::endl;
        x = relu(conv2->forward(x));
        std::cout << "conv2 no bugs" << std::endl;
        x = pool->forward(x);
        x = relu(conv3->forward(x));
        std::cout << "conv3 no bugs" << std::endl;
        x = pool->forward(x);
        x = relu(conv4->forward(x));
        std::cout << "conv4 no bugs" << std::endl;
        x = pool->forward(x);
        x = x.view({ x.size(0), -1 }); // Flatten the output for the fully connected layers
        x = dropout(relu(fc1->forward(x)));
        std::cout << "fc1 no bugs" << std::endl;
        x = dropout(relu(fc2->forward(x)));
        std::cout << "fc2 no bugs" << std::endl;
        x = torch::log_softmax(fc3->forward(x), 1);
        std::cout << "fc3 no bugs" << std::endl;

        std::cout << "Layers no bugs" << std::endl;

        return x;
    }
};
    
TORCH_MODULE(CNNModel);

void load_data_from_folder(std::string image_dir, std::string type, std::vector<std::string>& list_images, std::vector<int>& list_labels, int label);

void load_data_from_folder(std::string path, std::string type, std::vector<std::string>& list_images, std::vector<int>& list_labels, int label)
{
    long long hFile = 0; // Handle
    struct _finddata_t fileInfo;
    std::string pathName;
    if ((hFile = _findfirst(pathName.assign(path).append("/*.*").c_str(), &fileInfo)) == -1)
    {
        return;
    }
    do
    {
        const char* s = fileInfo.name;
        const char* t = type.data();

        if (fileInfo.attrib & _A_SUBDIR) // is a subdirectory
        {
            // read all the files in it
            if (strcmp(s, ".") == 0 || strcmp(s, "..") == 0) // subdirectory is . or ..
                continue;
            std::string sub_path = path + "/" + fileInfo.name;
            label++;
            load_data_from_folder(sub_path, type, list_images, list_labels, label);

        }
        else // determine whether it is a type file
        {
            if (strstr(s, t))
            {
                std::string image_path = path + "/" + fileInfo.name;
                list_images.push_back(image_path);
                list_labels.push_back(label);
            }
        }
    } while (_findnext(hFile, &fileInfo) == 0);
    return;
}

class ImageFolderDataset : public torch::data::datasets::Dataset<ImageFolderDataset> {
private:
    std::vector<std::string> image_paths;
    std::vector<int> labels;

public:
    int class_index = 0;
    ImageFolderDataset(const std::string& image_dir, const std::string& type) {
        load_data_from_folder(image_dir, type, image_paths, labels, class_index-1);
    }
    // Override get() function to return tensor at location index
    torch::data::Example<> get(size_t index) override {
        std::cout << "Loading data for index: " << index << std::endl;
        std::string image_path = image_paths.at(index);
        cv::Mat image = cv::imread(image_path);
        cv::resize(image, image, cv::Size(100, 100));

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

        int label = labels.at(index);
        torch::Tensor img_tensor = torch::from_blob(image.data, { image.rows, image.cols, 3 }, torch::kByte).permute({ 2, 0, 1 }); // Channels x Height x Width
        
        // Convert to float and scale pixels to [0, 1]
        img_tensor = img_tensor.to(torch::kFloat) / 255.0;

        // Normalize the tensor
        img_tensor = torch::data::transforms::Normalize<>({ 0.485, 0.456, 0.406 }, { 0.229, 0.224, 0.225 })(img_tensor);

        torch::Tensor label_tensor = torch::full({ 1 }, label);

        std::cout << "Data loaded for index: " << index << " with label: " << label << std::endl;
        return { img_tensor.clone(), label_tensor.clone() };
    }
    // Override size() function, return the length of data
    torch::optional<size_t> size() const override {
        return image_paths.size();
    };
};

int main() {
    // Hyperparameters
    const int64_t batch_size = 64;
    const size_t epochs = 10;
    const double learning_rate = 0.01;
    const std::string dataset_path = "dataset/";

    // Load training and validation datasets
    auto train_dataset = ImageFolderDataset(dataset_path + "Training", ".jpg")
                            .map(torch::data::transforms::Stack<>());
    auto val_dataset = ImageFolderDataset(dataset_path + "Test", ".jpg")
                            .map(torch::data::transforms::Stack<>());

    // Data loaders
    auto train_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(
                            std::move(train_dataset), batch_size);
    auto val_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
                            std::move(val_dataset), batch_size);

    std::cout << "Start training!" << std::endl;

    // Model
    CNNModel model;
    torch::Device device(torch::kCUDA);
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Training on GPU." << std::endl;
        model->to(device); // Move model to GPU
    }
    else {
        std::cout << "CUDA not available. Training on CPU." << std::endl;
        device = torch::Device(torch::kCPU);
        model->to(device); // Move model to CPU
    }

    std::cout << "Model no bugs" << std::endl;

    // Optimizer
    torch::optim::Adam optimizer(model->parameters(), torch::optim::AdamOptions(learning_rate)); // learning rate

    // Loss function
    torch::nn::NLLLoss criterion;

    float loss_train = 0; float loss_val = 0;
    float acc_train = 0.0; float acc_val = 0.0; float best_acc = 0.0;

    std::cout << "Training dataset size: " << train_dataset.size().value() << std::endl;
    std::cout << "Validation dataset size: " << val_dataset.size().value() << std::endl;
    
    for (size_t epoch = 1; epoch <= epochs; ++epoch) {
        // Training loop
        size_t batch_index_train = 0;
        size_t batch_index_val = 0;

        model->train();

        for (auto& batch : *train_loader) {
            std::cout << "Training batch loaded" << std::endl;
            auto data = batch.data.to(device);
            auto targets = batch.target.to(device);
            std::cout << "Batch data size: " << data.sizes() << std::endl;
            std::cout << "Batch target size: " << targets.sizes() << std::endl;

            optimizer.zero_grad(); // reset gradient
            torch::Tensor prediction = model->forward(data); // Execute the model on the input data.
            auto acc = prediction.argmax(1).eq(targets).sum();
            acc_train += acc.template item<float>() / batch_size;
            torch::Tensor loss = torch::nll_loss(prediction, targets);
            loss.backward();
            optimizer.step();
            loss_train += loss.item<float>();
            batch_index_train++;
            std::cout << "Epoch: " << epoch << " |Train Loss: " << loss_train / batch_index_train << " |Train Acc:" << acc_train / batch_index_train << "\r";
        }

        // Validation loop
        model->eval();

        for (const auto& batch : *val_loader) {
            std::cout << "Validation batch loaded" << std::endl;
            auto data = batch.data.to(device);
            auto targets = batch.target.to(device);
            std::cout << "Batch data size: " << data.sizes() << std::endl;
            std::cout << "Batch target size: " << targets.sizes() << std::endl;

            torch::Tensor prediction = model->forward(data);
            torch::Tensor loss = torch::nll_loss(prediction, targets);
            auto acc = prediction.argmax(1).eq(targets).sum();
            acc_val += acc.template item<float>() / batch_size;
            loss_val += loss.item<float>();
            batch_index_val++;
            std::cout << "Epoch: " << epoch << " |Val Loss: " << loss_val / batch_index_val << " |Valid Acc:" << acc_val / batch_index_val << "\r";
        }
        std::cout << std::endl;
        float epoch_acc_val = acc_val / batch_index_val;
        if (epoch_acc_val > best_acc) {
            torch::save(model, "best_result.pt");
            best_acc = epoch_acc_val;
        }
        loss_train = 0; loss_val = 0; acc_train = 0; acc_val = 0; batch_index_train = 0; batch_index_val = 0;
    }

    // Save the model
    torch::save(model, "result.pt");

    std::cout << "traning complete!" << std::endl;

    return 0;
}

