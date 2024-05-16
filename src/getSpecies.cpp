#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>

#include "getSpecies.h"

// Function to read species information from a file
std::vector<std::tuple<char, std::string, int, int>> readSpecies(const std::string& filename) {
    std::vector<std::tuple<char, std::string, int, int>> species; // Vector to store species information

    std::ifstream file("../input/" + filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return species; // Return empty vector if file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string name;
        char type;
        int regrowth, energy;

        std::istringstream iss(line);
        if (!(iss >> name >> type >> energy)) {
            std::cerr << "Error: Invalid data format in file " << filename << std::endl;
            continue; // Skip invalid lines
        }

        // Check if there's a regrowth factor
        // Check if there's a regrowth factor
        if (iss >> regrowth) {
            species.emplace_back(type, name, energy, regrowth);
        } else {
            // If there's no regrowth factor, set it to 0
            species.emplace_back(type, name, 0, energy);
        }

    }

    file.close();
    return species;
}
