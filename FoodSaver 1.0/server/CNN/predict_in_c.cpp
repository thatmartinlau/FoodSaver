#include <torch/script.h>
#include <torch/torch.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

std::vector<std::string> type =
{"Apple Braeburn", "Apple Crimson Snow", "Apple Golden 1", "Apple Golden 2", "Apple Golden 3", "Apple Granny Smith", 
"Apple Pink Lady", "Apple Red 1", "Apple Red 2", "Apple Red 3", "Apple Red Delicious", "Apple Red Yellow 1", "Apple Red Yellow 2", 
"Apricot", "Avocado", "Avocado ripe", "Banana", "Banana Lady Finger", "Banana Red", "Beetroot", "Blueberry", "Cactus fruit", 
"Cantaloupe 1", "Cantaloupe 2", "Carambula", "Cauliflower", "Cherry 1", "Cherry 2", "Cherry Rainier", "Cherry Wax Black", 
"Cherry Wax Red", "Cherry Wax Yellow", "Chestnut", "Clementine", "Cocos", "Corn", "Corn Husk", "Cucumber Ripe", "Cucumber Ripe 2", 
"Dates", "Eggplant", "Fig", "Ginger Root", "Granadilla", "Grape Blue", "Grape Pink", "Grape White", "Grape White 2", "Grape White 3", 
"Grape White 4", "Grapefruit Pink", "Grapefruit White", "Guava", "Hazelnut", "Huckleberry", "Kaki", "Kiwi", "Kohlrabi", "Kumquats", 
"Lemon", "Lemon Meyer", "Limes", "Lychee", "Mandarine", "Mango", "Mango Red", "Mangostan", "Maracuja", "Melon Piel de Sapo", 
"Mulberry", "Nectarine", "Nectarine Flat", "Nut Forest", "Nut Pecan", "Onion Red", "Onion Red Peeled", "Onion White", "Orange", 
"Papaya", "Passion Fruit", "Peach", "Peach 2", "Peach Flat", "Pear", "Pear 2", "Pear Abate", "Pear Forelle", "Pear Kaiser", 
"Pear Monster", "Pear Red", "Pear Stone", "Pear Williams", "Pepino", "Pepper Green", "Pepper Orange", "Pepper Red", "Pepper Yellow", 
"Physalis", "Physalis with Husk", "Pineapple", "Pineapple Mini", "Pitahaya Red", "Plum", "Plum 2", "Plum 3", "Pomegranate", 
"Pomelo Sweetie", "Potato Red", "Potato Red Washed", "Potato Sweet", "Potato White", "Quince", "Rambutan", "Raspberry", "Redcurrant", 
"Salak", "Strawberry", "Strawberry Wedge", "Tamarillo", "Tangelo", "Tomato 1", "Tomato 2", "Tomato 3", "Tomato 4", "Tomato Cherry Red", 
"Tomato Heart", "Tomato Maroon", "Tomato Yellow", "Tomato not Ripened", "Walnut", "Watermelon"};

// Function to transform and normalize the image
torch::Tensor transform_image(cv::Mat image) {
    // Resize image to 128x128
    cv::resize(image, image, cv::Size(128, 128));

    // Convert the image from BGR to RGB
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

    // Convert the image and normalize
    torch::Tensor tensor_image = torch::from_blob(image.data, {1, image.rows, image.cols, 3}, torch::kByte);
    tensor_image = tensor_image.permute({0, 3, 1, 2}); // Convert to CxHxW
    tensor_image = tensor_image.toType(torch::kFloat);
    tensor_image = tensor_image.div(255);
    tensor_image = torch::data::transforms::Normalize<>({ 0.485, 0.456, 0.406 }, { 0.229, 0.224, 0.225 })(tensor_image);

    return tensor_image;
}

int main() {
    // Load the image
    cv::Mat image = cv::imread("C:\\fruit360\\test.jpg", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error reading the image" << std::endl;
        return -1;
    }

    // Transform the image
    torch::Tensor tensor_image = transform_image(image);

    // Load the trained model
    torch::jit::script::Module module;
    try {
        module = torch::jit::load(R"(resnet18_fruits360.pth)");
    }
    catch (const c10::Error& e) {
        std::cerr << "Error loading the model: " << e.msg() << std::endl;
        return -1;
    }


    std::cout << "Model loaded successfully\n";

    // Predict the class of the fruit
    module.eval();
    torch::NoGradGuard no_grad;
    torch::Tensor prediction = module.forward({tensor_image}).toTensor();
    int predicted_class_index = prediction.argmax(1).item<int>();

    // Print the predicted class
    std::cout << "Predicted class: " << type[predicted_class_index] << std::endl;

    return 0;
}
