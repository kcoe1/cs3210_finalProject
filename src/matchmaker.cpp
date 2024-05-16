#include "map.h"
#include <string>
#include "matchmaker.h"
#include "getSpecies.h"

void printSpecies(std::string filename) {
    //initialize a vector of the species
    std::vector<std::tuple<char, std::string, int, int>> species;
    //store the species in the vector
    species = readSpecies("../input/"+filename);
    //iterate through the species and print their information
    for (const auto& s : species) {
        char type;
        std::string name;
        int regrowth, energy;
        std::tie(type, name, regrowth, energy) = s;
        if (name == "plant"){//different information is displayed for plants and animals
            std::cout << "Name: " << type << ", Type: " << name << ", Regrowth Coefficient: "
            << regrowth << ", Energy Points: " << energy << std::endl;
        }
        else {
            std::cout << "Name: " << type << ", Type: " << name << 
            ", Max Energy: " << energy << std::endl;
        }
    }
}