#include <torch/torch.h>

struct CNNModelImpl : torch::nn::Module {
    torch::nn::Conv2d conv1{nullptr}, conv2{nullptr}, conv3{nullptr}, conv4{nullptr};
    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
    torch::nn::Dropout dropout;
    torch::nn::ReLU relu;
    torch::nn::MaxPool2d pool{nullptr};

    CNNModelImpl() {
        // Convolutional layers
        conv1 = register_module("conv1", torch::nn::Conv2d(torch::nn::Conv2dOptions(3, 16, 5).padding(2)));
        conv2 = register_module("conv2", torch::nn::Conv2d(torch::nn::Conv2dOptions(16, 32, 5).padding(2)));
        conv3 = register_module("conv3", torch::nn::Conv2d(torch::nn::Conv2dOptions(32, 64, 5).padding(2)));
        conv4 = register_module("conv4", torch::nn::Conv2d(torch::nn::Conv2dOptions(64, 128, 5).padding(2)));

        fc1 = register_module("fc1", torch::nn::Linear(25088, 1024));
        fc2 = register_module("fc2", torch::nn::Linear(1024, 256));
        fc3 = register_module("fc3", torch::nn::Linear(256, 131)); // Assuming 131 output classes

        // Dropout
        dropout = register_module("dropout", torch::nn::Dropout(0.2));

        // Activation function
        relu = register_module("relu", torch::nn::ReLU());

        // Pooling layer
        pool = register_module("pool", torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2).stride(2)));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = relu(conv1->forward(x));
        x = pool->forward(x);
        x = relu(conv2->forward(x));
        x = pool->forward(x);
        x = relu(conv3->forward(x));
        x = pool->forward(x);
        x = relu(conv4->forward(x));
        x = pool->forward(x);
        x = x.view({x.size(0), -1}); // Flatten the output for the fully connected layers
        x = dropout(relu(fc1->forward(x)));
        x = dropout(relu(fc2->forward(x)));
        x = torch::log_softmax(fc3->forward(x), 1);
        return x;
    }
};

TORCH_MODULE(CNNModel);
