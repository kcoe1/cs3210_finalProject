#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "speciesInfo.h"

class Map {

private:
    std::string filename; //name of map file
    std::vector<std::vector<char>> map; // 2D vector to store the map
    int width;  // Width of the map (number of columns)
    int height; // Height of the map (number of rows)

public:
    // Constructor
    Map() : width(0), height(0) {}

    // Function to read the map dimensions and data from a file
    void readMap(const std::string& inputfile) {
        filename = inputfile;
        std::string locationFile = std::string("../input/") + inputfile;
        std::ifstream file(locationFile);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }

        // Read the map data
        std::string line;
        std::vector<char> row;
        while (std::getline(file, line)) {
            row.clear();
            for (char c : line) {
                row.push_back(c);
            }
            map.push_back(row);
        }

        // Update width and height
        width = map[0].size();
        height = map.size();

        file.close();
    }

    //record location of organisms
    std::vector<std::tuple<int, int, char>> findOrganisms() {
        std::vector<std::tuple<int, int, char>> organisms;
        for (int y = 0; y < getHeight(); ++y) {
            for (int x = 0; x < getWidth(); ++x) {
                // Check if the cell is occupied by something other than a space
                if (map[y][x] != ' ') {
                    // Create Organism object for the occupied cell
                    char type = map[y][x];
                    organisms.emplace_back(x, y, map[y][x]);
                    //std::cout << "Organism found at (" << x << ", " << y << ")" 
                    //<< " type: " << type << std::endl;
                }
            }
        }
        return organisms;
    }

    //not currently in use
    void printOrganisms(const std::vector<SpeciesInfo>& speciesInfo) {
        std::cout << "Guide: (3, 5) would be the 5th line from the top and the third space from the left." << "\n" << std::endl;
        for (const auto& info : speciesInfo) {
            std::cout << "Organism found at (" << info.xCoordinate << ", " << info.yCoordinate << ") type: " << info.character << std::endl;
        }
    }

    //print the map
    void mapPrinter(const std::vector<SpeciesInfo>& speciesInfo, int w, int h) {
        int maxX = w;
        int maxY = h;

        // Create a 2D grid to represent the map
        std::vector<std::vector<char>> map(maxY, std::vector<char>(maxX, ' '));

        // Fill the map with the data
        for (const auto& tuple : speciesInfo) {
            int x = tuple.xCoordinate;
            int y = tuple.yCoordinate;
            char value = tuple.character;
            map[y][x] = value;
        }

        // Print the map
        for (int y = 0; y < maxY; ++y) {
            for (int x = 0; x < maxX; ++x) {
                std::cout << map[y][x];
            }
            std::cout << std::endl;
        }
    }


    // Getter functions
    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    std::string getFilename() const {
        return filename;
    }
};

#endif //MAP.H