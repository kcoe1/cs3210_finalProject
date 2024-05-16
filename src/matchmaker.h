#ifndef MATCHMAKER_H
#define MATCHMAKER_H

#include <string>
#include <vector>
#include <tuple>
#include "getSpecies.h"
#include "speciesInfo.h"

void printSpecies(std::string filename);

class matchmaker {

public:

std::vector<SpeciesInfo> love(std::vector<std::tuple<int, int, char>> mapdata,
            std::vector<std::tuple<char, std::string, int, int>> speciesdata) {
    //Returns a vector<tuple<name, char, int, (for plants) int>>
    //This is the title ("plant"), character ("a"),
    //energy ("40"), and, for plants, the regrowth factor ("10")
    //The title will determine what object it is (ex: herbivore becomes
    //a herbivore object)
    std::vector<SpeciesInfo> result;

    for (const auto& tuple : mapdata) {
    int xCoord = std::get<0>(tuple);  // Get the x coordinate
    int yCoord = std::get<1>(tuple);  // Get the y coordinate
    char character = std::get<2>(tuple);  // Get the character from mapdata

    // Find the corresponding species in speciesdata
    for (const auto& species : speciesdata) {
        if (std::get<0>(species) == character) {
            // Species found, construct SpeciesInfo and add to result vector
            SpeciesInfo info;
            info.xCoordinate = xCoord;  // Set x coordinate
            info.yCoordinate = yCoord;  // Set y coordinate
            info.title = std::get<1>(species); // Set title
            info.character = std::get<0>(species); // Set character
            info.regrowthFactor = std::get<2>(species); // Set regrowth coefficient
            info.max_energy = std::get<3>(species); // Set max energy
            info.energy = std::get<3>(species); // set energy (that may change later)
            result.push_back(info); // Add it to the vector
            break;  // Stop searching for this character
        }
    }
}
    
    return result;
}

};

#endif // MATCHMAKER_H
