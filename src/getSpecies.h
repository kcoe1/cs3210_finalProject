#ifndef GETSPECIES_H
#define GETSPECIES_H

#include <string>
#include <vector>
#include <tuple>

// Function declaration for reading species information from a file
std::vector<std::tuple<char, std::string, int, int>> readSpecies(const std::string& filename);

#endif //GETSPECIES_H
