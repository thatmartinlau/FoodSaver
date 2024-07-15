//
// restClient.py
// This module defines a series of functions to perform basic http
// actions using curl.
//

#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function to handle writing data received from the server
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

// Function to perform a GET request using libcurl
long get(const std::string& url, const std::string& encoding, const std::string& user_agent = "", const std::string& referrer = "") {
    CURL* curl = curl_easy_init();
    if (!curl) {
        return -1;  // Return -1 if initialization fails
    }

    long httpCode = -1;  // Default, non-http response code

    std::string data;  // Variable to store received data

    // Set curl options for the GET request
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 8L);

    if (!user_agent.empty()) {
        curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent.c_str());
    }

    if (!referrer.empty()) {
        curl_easy_setopt(curl, CURLOPT_REFERER, referrer.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    try {
        // Perform the GET request and get the HTTP response code
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    } catch (...) {
        // Handle exceptions as needed
    }

    curl_easy_cleanup(curl);  // Cleanup libcurl resources

    return httpCode;  // Return the HTTP response code
}

// Function to perform a PUT request using libcurl
long put(const std::string& url, const std::string& data, const std::string& encoding, const std::map<std::string, std::string>& headers) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        return -1;  // Return -1 if initialization fails
    }

    long httpCode = -1;  // Default, non-http response code

    struct curl_slist* headerList = nullptr;
    for (const auto& header : headers) {
        std::string headerString = header.first + ": " + header.second;
        headerList = curl_slist_append(headerList, headerString.c_str());
    }

    // Set curl options for the PUT request
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");

    curl_easy_setopt(curl, CURLOPT_INFILESIZE, data.size());

    std::istringstream dataStream(data);
    curl_easy_setopt(curl, CURLOPT_READDATA, &dataStream);

    try {
        // Perform the PUT request and get the HTTP response code
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    } catch (...) {
        // Handle exceptions as needed
    }

    curl_slist_free_all(headerList);  // Free memory allocated for headers
    curl_easy_cleanup(curl);  // Cleanup libcurl resources

    return httpCode;  // Return the HTTP response code
}

