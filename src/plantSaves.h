#ifndef PLANTSAVES_H
#define PLANTSAVES_H

#include <string>

struct deadPlants {
    std::string title;
    char character;
    int energy;
    int max_energy;
    int regrowthFactor;
    int xCoordinate;
    int yCoordinate;
    int currentRegrowth;

    bool operator==(const deadPlants& other) const {
        return xCoordinate == other.xCoordinate &&
               yCoordinate == other.yCoordinate &&
               character == other.character &&
               title == other.title &&
               energy == other.energy &&
               max_energy == other.max_energy;
    }
};



#endif //PLANTSAVES_H