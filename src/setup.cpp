#include "setup.h"
#include "map.h"
#include "getSpecies.h"
#include "matchmaker.h"
#include "speciesInfo.h"
#include <vector>
#include <string>

std::vector<SpeciesInfo> setup::starter(std::string map, std::string species) {
    Map mapInstance; // Create an instance of the Map class
    mapInstance.readMap(map); // Read the map data
    std::vector<std::tuple<int, int, char>> mapdata = mapInstance.findOrganisms();
    std::vector<std::tuple<char, std::string, int, int>> speciesdata = readSpecies(species);

    std::vector<SpeciesInfo> orgList;

    matchmaker matcher;
    orgList = matcher.love(mapdata, speciesdata); // match organisms with species and save it to a vector

    return orgList;
}