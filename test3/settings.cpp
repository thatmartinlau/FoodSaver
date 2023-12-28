#include <iostream>
#include <string>

// Configuration settings for the project
namespace Configuration {
    // Encoding setting
    const std::string ENCODING = "utf-8";

    // User agent setting
    const std::string UA = "FoodSaver/1.7 +http://github.com/thatmartinlau/FoodSaver";

    // Pause crawler setting
    const bool PAUSE_CRAWLER = true;

    // Pause time range setting
    const std::pair<int, int> PAUSE_TIME_RANGE = std::make_pair(10, 60);

    // Output folder setting
    const std::string OUTPUT_FOLDER = "/tmp";

    // ARMS configuration settings
    struct ARMSConfig {
        std::string SERVER;
        std::string API_KEY;
        std::string API_SEED;
    };

    // Default ARMS settings
    const ARMSConfig ARMS = { "", "", "" };
}
