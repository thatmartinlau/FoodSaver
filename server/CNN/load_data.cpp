#include <torch/torch.h>
#include <filesystem>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace fs = std::filesystem;

class ImageFolderDataset: public torch::data::datasets::Dataset<ImageFolderDataset> {
    std::vector<std::string> image_paths;
    std::vector<int> labels;
    std::unordered_map<std::string, int> class_to_label;
    torch::data::transforms::Compose<> transforms;

public:
    ImageFolderDataset(const std::string& root_path, const torch::data::transforms::Compose<>& transforms)
        : transforms(transforms) {
        // Assign labels to each class (folder)
        int label = 0;
        for (const auto& entry : fs::directory_iterator(root_path)) {
            if (fs::is_directory(entry)) {
                class_to_label[entry.path().filename()] = label++;
            }
        }

        // Load image paths and labels
        for (const auto& class_entry : fs::directory_iterator(root_path)) {
            if (fs::is_directory(class_entry)) {
                int current_label = class_to_label[class_entry.path().filename()];
                for (const auto& image_entry : fs::directory_iterator(class_entry.path())) {
                    if (fs::is_regular_file(image_entry) && 
                        (image_entry.path().extension() == ".jpg" || image_entry.path().extension() == ".png")) {
                        image_paths.push_back(image_entry.path());
                        labels.push_back(current_label);
                    }
                }
            }
        }
    }

    torch::data::Example<> get(size_t index) override {
        std::string image_path = image_paths.at(index);
        int label = labels.at(index);

        auto image = torch::vision::read_image(image_path);
        image = transforms->forward(image);

        return {image, torch::tensor(label)};
    }

    torch::optional<size_t> size() const override {
        return image_paths.size();
    }
};
