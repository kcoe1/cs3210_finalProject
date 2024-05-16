// SpeciesInfo.h

#ifndef SPECIESINFO_H
#define SPECIESINFO_H

#include <string>

//data structure for all organisms (except regrowing plants)
struct SpeciesInfo {
    std::string title;
    char character;
    int energy;
    int max_energy;
    int regrowthFactor;
    int xCoordinate;
    int yCoordinate;

    //used to indentify specific entries in the SpeciesInfo vector
    bool operator==(const SpeciesInfo& other) const {
        return xCoordinate == other.xCoordinate &&
               yCoordinate == other.yCoordinate &&
               character == other.character &&
               title == other.title &&
               energy == other.energy &&
               max_energy == other.max_energy;
    }
};

#endif // SPECIESINFO_H