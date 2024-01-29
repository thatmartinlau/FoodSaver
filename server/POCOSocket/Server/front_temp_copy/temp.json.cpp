#include <iostream> //for inputs and outputs
#include <fstream> //to read and write files
#include <nlohmann/json.hpp> //import json library

using namespace std;
using json = nlohmann::json;

// code a function that can cin the bachelor data from the website

// Function to read JSON from a file: reading the recipe dataset
json readJsonFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        json jsonData;
        file >> jsonData;
        file.close();
        return jsonData;
    } else {
        throw std::runtime_error("Unable to open file: " + filename);
    }
}

// Function to write JSON to a file: this will be used to add the Bachelor recipes from the website into the JSON database ( what Cyriac is working on) 
void writeJsonToFile(const json& jsonData, const std::string& filename) { //remember to write it in the format of a json with name, ingredients, time, diet restriction and instructions  
    std::ofstream file(filename);
    if (file.is_open()) {
        file << jsonData << std::endl;  
        file.close();
    } else {
        throw std::runtime_error("Unable to create file: " + filename);
    }
}

json newData = {{"key1", "value1"}, {"key2", 42}}; // example of data that will be added to the file 

void mergeJsonFiles(const std::string& sourceFile, const std::string& destinationFile) { // make edit: at the end, on the 1st layer, add number n of the nth recipe (key), and then the new json (value)
    std::ifstream sourceStream(sourceFile); // Read the source JSON file (user recipe)
    if (!sourceStream.is_open()) {
        throw std::runtime_error("Unable to open source file: " + sourceFile);
    }
  
    json sourceJson;     // Parse the source JSON data
    sourceStream >> sourceJson;
    sourceStream.close();
    
    std::ifstream destinationStream(destinationFile); // Read the destination JSON file (existing recipe dataset)
    if (!destinationStream.is_open()) {
        throw std::runtime_error("Unable to open destination file: " + destinationFile);
    }
    
    json destinationJson; // Parse the destination JSON data
    destinationStream >> destinationJson;
    destinationStream.close();
    
    destinationJson.merge_patch(sourceJson); // Merge the information (add the user recipe)

    // Write the merged JSON to the destination file
    std::ofstream destinationWriteStream(destinationFile);
    if (!destinationWriteStream.is_open()) {
        throw std::runtime_error("Unable to open destination file for writing: " + destinationFile);
    }
    destinationWriteStream << destinationJson;  
    destinationWriteStream.close();
    std::cout << "Merge successful. Updated data written to: " << destinationFile << std::endl;
}
