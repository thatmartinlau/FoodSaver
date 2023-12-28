#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "RecipeBook.hpp"


// Queue class for thread-safe queue operations
template <typename T>
class Queue {
public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mutex_);
        T value = queue_.front();
        queue_.pop();
        return value;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
};

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to fetch and process URLs
void fetch(const std::function<void(const std::string&)>& src, bool save, const std::string& db,
           const std::string& collection, Queue<std::string>& pending, Queue<std::string>& fetched) {
    while (true) {
        std::string url = pending.pop();
        if (url.empty() || fetched.pop() == url) {
            pending.push(url);  // Re-add the URL to the queue if it was already processed
        } else {
            try {
                // Fetch the recipe and process related URLs
                src(url);
                if (save) {
                    // Save the recipe
                    // TODO: Implement the save function
                }
                if (!db.empty() && !collection.empty()) {
                    // Store the recipe in the database
                    // TODO: Implement the store function
                }
                fetched.push(url);
                // Add related URLs to the pending queue
                // TODO: Implement the getOtherRecipeLinks function
            } catch (...) {
                std::cerr << "[warning] could not fetch: " << url << std::endl;
            }
            pending.push(url);
            // Pause for a random interval between PAUSE_TIME_RANGE seconds before continuing
            std::this_thread::sleep_for(std::chrono::seconds(rand() % (PAUSE_TIME_RANGE.second - PAUSE_TIME_RANGE.first + 1) + PAUSE_TIME_RANGE.first));
        }
    }
}

int main(int argc, char* argv[]) {
    // Seed for random number generation
    std::srand(std::time(0));

    // Available site modules
    std::vector<std::function<void(const std::string&)>> available = {
        AllRecipes, Epicurious, FoodNetwork, Saveur, SiroGohan, WilliamsSonoma
    };

    // Command-line arguments handling
    if (argc < 4) {
        // Define the usage
        std::cout << argv[0] << " [site: (AllRecipes|Epicurious|FoodNetwork|Saveur|SiroGohan|WilliamsSonoma)] "
                  << "[file of seed urls] [threads] [save() (defaults to True)] "
                  << "[store() database (defaults to None)] [store() collection (defaults to None)]" << std::endl;
    } else {
        // Do the deed
        std::string siteName = toLower(argv[1]);
        auto it = std::find_if(available.begin(), available.end(), [&siteName](const auto& site) {
            return toLower(site.target_type().name()) == siteName;
        });

        if (it == available.end()) {
            std::cout << "Sorry, that site is not yet available" << std::endl;
        } else {
            // Parse command-line arguments
            int threads = std::stoi(argv[3]);
            bool save = true;
            if (argc > 4) {
                save = toLower(argv[4]) == "true" || argv[4][0] == 't';
            }

            std::string db = argc > 5 ? argv[5] : "";
            std::string collection = argc > 6 ? argv[6] : "";

            // Create and start worker threads
            std::vector<std::thread> workers;
            Queue<std::string> pending;
            Queue<std::string> fetched;

            for (int i = 0; i < threads; ++i) {
                workers.emplace_back(fetch, *it, save, db, collection, std::ref(pending), std::ref(fetched));
            }

            // Load the file of initial URLs and seed the pending queue
            std::ifstream file(argv[2]);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    pending.push(line);
                }
                file.close();
            }

            // Wait for all threads to finish processing
            for (auto& worker : workers) {
                worker.join();
            }

            // Show the summary
            std::cout << "Fetched and parsed:" << std::endl;
            std::set<std::string> uniqueFetched;
            while (!fetched.empty()) {
                std::string link = fetched.pop();
                uniqueFetched.insert(link);
            }

            int i = 1;
            for (const auto& link : uniqueFetched) {
                std::cout << i << "\t" << link << std::endl;
                ++i;
            }
        }
    }

    return 0;
}
