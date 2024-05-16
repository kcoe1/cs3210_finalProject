// main.cpp
#include <string>
#include <algorithm>
#include <random>
#include <limits> // used for EXTRA CREDIT

#include "map.h"
#include "matchmaker.h"
#include "setup.h"
#include "speciesInfo.h"
#include "plantSaves.h"

//crreate map opject
Map mapMaker(std::string mapInput) {
    
    Map map;
    map.readMap(mapInput);

    return map;
}

//return width of map
int mapW(Map map) {
    int w = map.getWidth();
    return w;
}

//return height of map
int mapH(Map map) {
    int h = map.getHeight();
    return h;
}

//print out the dimensions of the map (width and height)
void mapSize(Map map) {
    std::cout << "Width of the map: " << mapW(map) << std::endl;
    std::cout << "Height of the map: " << mapH(map) << std::endl;
    //std::cout << "Filename: " << map.getFilename() << std::endl;
}

//return a vector of the organisms on the map
std::vector<std::tuple<int, int, char>> mapOrganisms(Map map) { 

    std::cout << '\n';
    std::vector<std::tuple<int, int, char>> organismList;
    organismList = map.findOrganisms();

    return organismList;

}

//calls the printSpecies method
void basicSpeciesTest(std::string speciesInput) {

    //Species test
    printSpecies(speciesInput);

}

//prompt the user for an input, integer 1-7
int getIntInput() {
    std::string answer;
    int numAn;
    while (true) {
        // Get input
        std::cout << "Enter an integer between 1 and 3: ";
        std::getline(std::cin, answer);

        try {
            // Attempt to convert string to integer
            numAn = std::stoi(answer);
            if ((numAn >= 1 && numAn <= 7) || numAn == 111) {
                break; // If successful and within range, exit the loop
            } else {
                std::cerr << "Invalid input. Please enter an integer between 1 and 3." << std::endl;
            }
        } catch (std::invalid_argument& e) {
            // Catch exception if conversion fails
            std::cerr << "Invalid input. Please enter an integer between 1 and 3." << std::endl;
        }
    }
    return numAn;
}

//promt the user for an input, integer > 0
int getAnyIntInput() {
    std::string answer;
    int numAn;
    while (true) {
        std::cout << "My choice is: ";
        // Get input
        std::getline(std::cin, answer);

        try {
            // Attempt to convert string to integer
            numAn = std::stoi(answer);
            if (numAn > 0) {
                break; // If successful and within range, exit the loop
            } else {
                std::cerr << "Invalid input. Please enter an integer greater than 0." << std::endl;
            }
        } catch (std::invalid_argument& e) {
            // Catch exception if conversion fails
            std::cerr << "Invalid input. Please enter an integer greater than 0." << std::endl;
        }
    }
    return numAn;
}

//EXTRA CREDIT
int getMakerInput() {
    std::string answer;
    int numAn;
    while (true) {
        // Get input
        std::cout << "Enter an integer between 1 and 3: ";
        std::getline(std::cin, answer);

        try {
            // Attempt to convert string to integer
            numAn = std::stoi(answer);
            if (numAn >= 1 && numAn <= 3) {
                break; // If successful and within range, exit the loop
            } else {
                std::cerr << "Invalid input. Please enter an integer between 1 and 3." << std::endl;
            }
        } catch (std::invalid_argument& e) {
            // Catch exception if conversion fails
            std::cerr << "Invalid input. Please enter an integer between 1 and 3." << std::endl;
        }
    }
    return numAn;
}

//EXTRA CREDIT
int getCoordInput() {
    std::string answer;
    int numAn;
    while (true) {
        std::cout << "This is my choice: ";
        // Get input
        std::getline(std::cin, answer);

        try {
            // Attempt to convert string to integer
            numAn = std::stoi(answer);
            if (numAn >= 0) {
                break; // If successful and within range, exit the loop
            } else {
                std::cerr << "Invalid input. Please enter an integer greater than 0." << std::endl;
            }
        } catch (std::invalid_argument& e) {
            // Catch exception if conversion fails
            std::cerr << "Invalid input. Please enter an integer greater than 0." << std::endl;
        }
    }
    return numAn;
}

//print out the simulation menu
int welcomeMessage() {
    std::cout << "\t" << "Welcome to the S I M U L A T I O N" << std::endl;
    std::cout << "\n" << "What would you like to do?" << std::endl;
    //std::cout << "4. Check my map dimensions." << std::endl;
    //std::cout << "5. Check what species I was given." << std::endl;
    //std::cout << "6. Check a list of animals on the map." << std::endl;
    //std::cout << "7. Check the map visualization." << std::endl;
    std::cout << "1. Run 1 interation of the simulation." << std::endl;
    std::cout << "2. Run a batch of iterations." << std::endl;
    std::cout << "3. End the simulation." << "\n" << std::endl;
    std::cout << "I would like to: ";

    int answer;
    answer = getIntInput();
    return answer;
}

//print the information for all organisms on the map
void printSpeciesInfo(std::vector<SpeciesInfo>& speciesInfo) {
    for (auto& info : speciesInfo) {
        if (info.title != "plant") {
            std::cout << "Name: " << info.character << std::endl;
            std::cout << "Type: " << info.title << std::endl;
            if (info.title == "plant") {
                std::cout << "Regrowth Factor: " << info.regrowthFactor << std::endl;
                std::cout << "Energy Points: " << info.max_energy << std::endl;
            }
            else {
                std::cout << "Max Energy: " << info.max_energy << std::endl;
                std::cout << "Current Energy Level: " << info.energy << std::endl;
            }
            std::cout << "Line number from the top: " << info.yCoordinate << std::endl;
            std::cout << "Space number from the left: " << info.xCoordinate << std::endl;
            std::cout << std::endl; // Add a newline between each species
        }
    }
}

//EXTRA CREDIT
//find an empty spot on the map
std::tuple<int, int> spotFinder(const Map& map, const std::vector<SpeciesInfo>& speciesInfo) {
    for (int i = 0; i < map.getWidth(); i++) {
        for (int j = 0; j < map.getHeight(); j++) {
            bool spotOccupied = false;
            for (const auto& org : speciesInfo) {
                if (org.xCoordinate == i && org.yCoordinate == j) {
                    spotOccupied = true;
                    break;
                }
            }
            if (!spotOccupied) {
                return std::make_tuple(i, j); // Found an empty spot, return its coordinates
            }
        }
    }
    // If no empty spot is found, return a default value
    return std::make_tuple(-1, -1); // Indicate no empty spot found
}

//EXTRA CREDIT
char getCharacterInput(const std::vector<SpeciesInfo>& speciesInfo) {
    char input;
    bool validInput = false;

    do {
        std::cout << "Enter a character: ";
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        if (std::cin.fail()) { // Check if input failed (e.g., due to invalid type)
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a single character." << std::endl;
        } else if (std::cin.gcount() > 1) { // Check if more than one character was entered
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear excess characters
            std::cout << "Please enter only one character." << std::endl;
        } else {
            // Check if the entered character is already in use
            auto it = std::find_if(speciesInfo.begin(), speciesInfo.end(),
                                   [&input](const SpeciesInfo& info) {
                                       return info.character == input;
                                   });
            if (it != speciesInfo.end()) {
                std::cout << "This character is already in use. Please choose another one." << std::endl;
            } else {
                validInput = true;
            }
        }
    } while (!validInput);

    return input;
}

//EXTRA CREDIT
void speciesMaker(std::vector<SpeciesInfo>& speciesInfo, int w, int h, Map map) {
    std::cout << "\n\n" << "This is part of my extra credit." << "\n\n" << std::endl;
    std::cout << "\t" << "Weclome to Species Maker!" << "\n" << std::endl;
    std::cout << "Here you will have to opprotunity to create a custom species to add to the map." << std::endl;
    std::cout << "First, do you want to make a 1. Plant, 2. Herbivore, or 3. Omnivore?" << std::endl;
    std::cout << "Please enter your answer as integer 1, 2, or 3." << std::endl;
    int num;
    SpeciesInfo newSpecies;
    num = getMakerInput();
    if (num == 1) {// plant
        newSpecies.title = "plant";
    }
    else if (num == 2) {// herbivore
        newSpecies.title = "herbivore";
    }
    else {//omnivore
        newSpecies.title = "omnivore";
    }
    std::cout << "\n" << "Nice Choice! Now let's choose its energy level." << std::endl;
    int energy;
    energy = getAnyIntInput();
    newSpecies.energy = energy;
    newSpecies.max_energy = energy;
    if (energy >= 100) {
        std::cout << "\n" << "Wow that is a strong organism!" << std::endl;
    }
    else {
        std::cout << "\n" << "This will make a great fit in our ecosystem." << std::endl;
    }
    if (newSpecies.title == "plant") {
        std::cout << "\n" << "It seems you've chosen a plant! We need a regrowth factor." << std::endl;
        int rF;
        rF = getAnyIntInput();
        newSpecies.regrowthFactor = rF;
    }
    else {
        newSpecies.regrowthFactor = 0;
    }
    std::cout << "\n" << "Now we need somewhere to place it on the map." << std::endl;
    std::cout << "Please choose an x and y coordinate so that it doesn't overlap a current organism." << std::endl;
    auto emptySpot = spotFinder(map, speciesInfo);
    std::cout << "(" << std::get<0>(emptySpot) << ", " << std::get<1>(emptySpot) << ") is available!" << std::endl;
    bool goodSpot = false;
    int x;
    int y;
    while (!goodSpot) {
        std::cout << "\nPlease enter your x coordinate:" << std::endl;
        x = getCoordInput();
        std::cout << "\nPlease enter your y coordinate:" << std::endl;
        y = getCoordInput();

        if (x >= 0 && x < w && y >= 0 && y < h) {
            bool spotOccupied = false;
            for (const auto& org : speciesInfo) {
                if (org.xCoordinate == x && org.yCoordinate == y) {
                    spotOccupied = true;
                    std::cout << "This spot is occupied! Please try again." << std::endl;
                    break;
                }
            }
            if (!spotOccupied) {
                goodSpot = true; // Set goodSpot to true if the spot is valid and unoccupied
            }
        } 
        else {
            std::cout << "This spot is out of bounds! Please try again." << std::endl;
        }
    }
    newSpecies.xCoordinate = x;
    newSpecies.yCoordinate = y;
    std::cout << "\nGreat! We're almost done. Now we need to give it a name." << std::endl;
    std::cout << "\nPlease enter a character (such as 'R') as its name." << std::endl;
    char name;
    name = getCharacterInput(speciesInfo);
    newSpecies.character = name;
    std::cout << "\nThanks for making your own species for the simulation!" << std::endl;
    std::cout << "Let's see it on the map." << std::endl;
    speciesInfo.push_back(newSpecies);
}

//revive a plant that has fully regrown
void revivePlant(std::vector<deadPlants>& deadPlantsVector, std::vector<SpeciesInfo>& speciesInfo, deadPlants& plant) {
    // Now add the revived plant back to the SpeciesInfo vector
    //std::cout << "reviving " << plant.character << std::endl;
    SpeciesInfo newPlant;
    // Populate newPlant with the properties of the revived plant
    // For example:
    newPlant.title = "plant";
    newPlant.character = plant.character;
    newPlant.energy = plant.energy;
    newPlant.max_energy = plant.max_energy;
    newPlant.xCoordinate = plant.xCoordinate;
    newPlant.yCoordinate = plant.yCoordinate;
    newPlant.regrowthFactor = plant.regrowthFactor;

    // Push the newPlant back to the speciesInfo vector
    speciesInfo.push_back(newPlant);

    // Find the iterator pointing to the element to remove
    auto it = std::find(deadPlantsVector.begin(), deadPlantsVector.end(), plant);

    // If the element is found, erase it from the vector
    if (it != deadPlantsVector.end()) {
        deadPlantsVector.erase(it);
    }
}

//increase the regrow counter and check if the plant can regrow
void plantRegrow(std::vector<deadPlants>& deadPlants, std::vector<SpeciesInfo>& speciesInfo) {
    for (auto& plant : deadPlants) {
        //std::cout << plant.character << " is trying to regrow!" << std::endl;
        plant.currentRegrowth += 1;
        //std::cout << plant.character << "'s regrowth level is " << plant.currentRegrowth << std::endl;
        //std::cout << plant.character << " needs " << plant.regrowthFactor << " to regrow" << std::endl;
        bool overlap = false;
        if (plant.currentRegrowth >= plant.regrowthFactor) {
            for (auto& animal : speciesInfo) {
                if (animal.xCoordinate == plant.xCoordinate && animal.yCoordinate == plant.yCoordinate) {
                    overlap = true;
                    //std::cout << "overlap with " << animal.character;
                }
            }
            if (overlap == false) {
                revivePlant(deadPlants, speciesInfo, plant);
            }
        } else {
            continue;
        }
    }
}

//remove an organism from the SpeciesInfo vector
void removeElement(std::vector<SpeciesInfo>& speciesInfo, SpeciesInfo& elementToRemove, std::vector<deadPlants>& deadPlantsVector) {
    // Check if the element to remove is a plant
    if (elementToRemove.title == "plant") {
        //std::cout << elementToRemove.character << " is being saved for regrowth" << std::endl;
        // Save the plant for regrowth
        deadPlants deadPlant;
        // Populate deadPlant with the properties of the plant
        deadPlant.title = elementToRemove.title;
        deadPlant.character = elementToRemove.character;
        deadPlant.energy = elementToRemove.energy;
        deadPlant.max_energy = elementToRemove.max_energy;
        deadPlant.xCoordinate = elementToRemove.xCoordinate;
        deadPlant.yCoordinate = elementToRemove.yCoordinate;
        deadPlant.regrowthFactor = elementToRemove.regrowthFactor;
        deadPlant.currentRegrowth = 0;
        // Add other properties as needed
        deadPlantsVector.push_back(deadPlant);
    }

    // Find the iterator pointing to the element to remove
    auto it = std::find(speciesInfo.begin(), speciesInfo.end(), elementToRemove);

    // If the element is found, erase it from the vector
    if (it != speciesInfo.end()) {
        speciesInfo.erase(it);
    }
}

//animal makes a random move on the map
void randomMovement(std::vector<SpeciesInfo>& speciesInfo, SpeciesInfo& info, int w, int h) {
    //std::cout << "random move" << std::endl;
    if (info.title == "plant") {
        return;
    }
    
    int dx_list[] = { -1, 1}; // Check in x-direction (left, right)
    int dy_list[] = {-1, 1}; // Check in y-direction (up, down)
    
    // Create a random device to generate random numbers.
    std::random_device rd;
    std::mt19937 g(rd());

    int n = rand() % 2;
    //std::cout << "n is " << n << std::endl;

    // Shuffle the directions randomly
    std::shuffle(std::begin(dx_list), std::end(dx_list), g);
    std::shuffle(std::begin(dy_list), std::end(dy_list), g);

    bool moved = false;
    int dx = 0;
    int dy = 0;
    for (int i = 0; i < 2; ++i) {
        if (n == 0) {
            dx = dx_list[i];
            dy = 0;
        }
        else {
            dx = 0;
            dy = dy_list[i];
        }

        // Calculate new position
        int new_x = info.xCoordinate + dx;
        int new_y = info.yCoordinate + dy;
        //std::cout << "trying to move to (" << new_x << ", " << new_y << ")" << std::endl;

        // Check if the new position is within bounds
        if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h) {

            // Check if there's any overlapping with other creatures
            bool overlap = false;
            for (auto& other : speciesInfo) {
                if (&info != &other && new_x == other.xCoordinate && new_y == other.yCoordinate) {
                    //std::cout << "overlap found with " << other.character << std::endl;
                    overlap = true;
                    break;
                }
            }

            // If there's no overlap, update the position and break the loop
            if (!overlap) {
                info.xCoordinate = new_x;
                info.yCoordinate = new_y;
                info.energy -= 1;
                moved = true;
                //std::cout << "the move has been made" << std::endl;
                break;
            }
        }
    }
    if (!moved) {
        //std::cout << "trying again" << std::endl;
        if (n == 0) {
            n = 1;
        } else {
            n = 0;
        }
        for (int i = 0; i < 2; ++i) {
            if (n == 0) {
                dx = dx_list[i];
                dy = 0;
            }
            else {
                dx = 0;
                dy = dy_list[i];
            }

            // Calculate new position
            int new_x = info.xCoordinate + dx;
            int new_y = info.yCoordinate + dy;

            // Check if the new position is within bounds
            if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h) {

                // Check if there's any overlapping with other creatures
                bool overlap = false;
                for (auto& other : speciesInfo) {
                    if (&info != &other && new_x == other.xCoordinate && new_y == other.yCoordinate) {
                        overlap = true;
                        break;
                    }
                }

                // If there's no overlap, update the position and break the loop
                if (!overlap) {
                    info.xCoordinate = new_x;
                    info.yCoordinate = new_y;
                    info.energy -= 1;
                    moved = true;
                    break;
                }
            }
        }
    }
    //std::cout << "end of random movement: xC is " << info.xCoordinate << " and yC is " << info.yCoordinate << std::endl;
}

//animal makes a move on the map based on surrounding organisms
std::vector<SpeciesInfo> incentiveMovement(std::vector<SpeciesInfo>& speciesInfo, SpeciesInfo& info, int w, int h, std::vector<deadPlants>& deadPlants) {
    //std::cout << "incentive move" << std::endl;
    int dx_list[] = {0, 0, -1, 1}; // Check in x-direction (left, right)
    int dy_list[] = {-1, 1, 0, 0}; // Check in y-direction (up, down)

    if (info.title == "herbivore") {
        //std::cout << "herbivore incentive movement" << std::endl;
        bool noOmni = true;
        for (int i = 0; i < 4; ++i) {
            int new_x = info.xCoordinate + dx_list[i];
            int new_y = info.yCoordinate + dy_list[i];
            
            // Check if the new position is occupied by an omnivore
            for (auto& other : speciesInfo) {
                if (new_x == other.xCoordinate && new_y == other.yCoordinate &&
                    other.title == "omnivore") {
                    int new_x_away = info.xCoordinate - dx_list[i]; // Move in the opposite direction
                    int new_y_away = info.yCoordinate - dy_list[i];

                    // Check if the new position is within bounds
                    if (new_x_away >= 0 && new_x_away < w && new_y_away >= 0 && new_y_away < h) {
                        // Check if there's any overlapping with other creatures
                        bool overlap = false;
                        for (auto& other : speciesInfo) {
                            if (&info != &other && new_x_away == other.xCoordinate && new_y_away == other.yCoordinate) {
                                //std::cout << "h trying to run away" << std::endl;
                                //consider what happens if its trying to run into a plant
                                if (other.title == "plant") {
                                    if (other.energy + info.energy <= info.max_energy) {
                                        continue;
                                    }
                                    else {
                                        //std::cout << "no luck" << std::endl;
                                        overlap = true;
                                        break;
                                    }
                                }
                            }
                        }

                        // If there's no overlap, update the position and break the loop
                        if (!overlap) {
                            info.xCoordinate = new_x_away;
                            info.yCoordinate = new_y_away;
                            info.energy -= 1;
                            noOmni = false;
                            return speciesInfo;
                        }
                    }
                }
            }
        }
        if (noOmni = true) {
            for (int i = 0; i < 4; ++i) {
                for (auto& other : speciesInfo) {
                    int new_x = info.xCoordinate - dx_list[i]; // Move in the opposite direction
                    int new_y = info.yCoordinate - dy_list[i];
                    if (new_x == other.xCoordinate && new_y == other.yCoordinate) {
                        if (info.energy + other.energy <= info.max_energy) {
                            info.xCoordinate = new_x;
                            info.yCoordinate = new_y;
                            info.energy -= 1;
                            info.energy += other.energy;

                            removeElement(speciesInfo, other, deadPlants);
                                    
                            return speciesInfo;
                        }
                    }
                }
            }
        }
        randomMovement(speciesInfo, info, w, h);
    }
    else {
        //std::cout << "omnivore incentive movement" << std::endl;
        for (int i = 0; i < 4; ++i) {
            int new_x = info.xCoordinate + dx_list[i];
            int new_y = info.yCoordinate + dy_list[i];
            
            // Check if the new position is occupied by a herbivore
            for (auto& other : speciesInfo) {
                if (new_x == other.xCoordinate && new_y == other.yCoordinate &&
                    other.title == "herbivore" && other.energy + info.energy <= info.max_energy) {
                    //std::cout << "time to eat!" << std::endl;
                    info.xCoordinate = new_x;
                    info.yCoordinate = new_y;
                    info.energy -= 1;
                    info.energy += other.energy;
                    removeElement(speciesInfo, other, deadPlants);
                    
                    return speciesInfo;
                }
            }
            for (auto& other : speciesInfo) {
                if (new_x == other.xCoordinate && new_y == other.yCoordinate &&
                    other.title == "plant" && other.energy + info.energy <= info.max_energy) {
                    //std::cout << "time to munch!" << std::endl;
                    info.xCoordinate = new_x;
                    info.yCoordinate = new_y;
                    info.energy -= 1;
                    info.energy += other.energy;

                    removeElement(speciesInfo, other, deadPlants);

                    return speciesInfo;
                }
            }
        }
        randomMovement(speciesInfo, info, w, h);
    }
    return speciesInfo;
}

//check if the animal has an incentive in its surrounding area
bool isThereIncentive(std::vector<SpeciesInfo> speciesInfo, SpeciesInfo& info) {
    // Define directions for checking
    int dx_list[] = {0, 0, -1, 1}; // Check in x-direction (left, right)
    int dy_list[] = {-1, 1, 0, 0}; // Check in y-direction (up, down)

    if (info.title == "herbivore") {
        for (int i = 0; i < 4; ++i) {
            int new_x = info.xCoordinate + dx_list[i];
            int new_y = info.yCoordinate + dy_list[i];
            
            // Check if the new position is occupied by a plant
            for (auto& other : speciesInfo) {
                if (new_x == other.xCoordinate && new_y == other.yCoordinate &&
                    (other.title == "plant" || other.title == "omnivore")) {
                    //std::cout << "h incentive found at (" << new_x << ", " << new_y << ")" << std::endl;
                    //std::cout << "h incentive is " << other.character << " at (" << other.xCoordinate << ", " << other.yCoordinate << ")" << std::endl;
                    return true; // Plant or omnivore found, there's an incentive
                }
            }
        }
    }

    else if (info.title == "omnivore") {
        for (int i = 0; i < 4; ++i) {
            int new_x = info.xCoordinate + dx_list[i];
            int new_y = info.yCoordinate + dy_list[i];
            
            // Check if the new position is occupied by a plant or a herbivore
            for (auto& other : speciesInfo) {
                if (new_x == other.xCoordinate && new_y == other.yCoordinate && 
                    (other.title == "plant" || other.title == "herbivore")) {
                    //std::cout << "o incentive found at (" << new_x << ", " << new_y << ")" << std::endl;
                    //std::cout << "o incentive is " << other.character << " at (" << other.xCoordinate << ", " << other.yCoordinate << ")" << std::endl;
                    return true; // Plant or herbivore found, there's an incentive
                }
            }
        }
    }
    
    // No incentive found in any direction
    return false;
}

//check if an animal can move
bool canIMove(std::vector<SpeciesInfo> speciesInfo, SpeciesInfo& info, int w, int h) {
    // Make sure no plants are moving
    if (info.title == "plant") {
        return false;
    }
    // Initialize a flag to check if any movement is legal
    bool can_move = false;
    // Check all adjacent cells for possible movement
    int dx_list[] = {0, 0, -1, 1}; // Movement in x-direction (left, right)
    int dy_list[] = {-1, 1, 0, 0}; // Movement in y-direction (up, down)
    for (int i = 0; i < 4; ++i) {
        // Calculate new coordinates
        int new_x = info.xCoordinate + dx_list[i];
        int new_y = info.yCoordinate + dy_list[i];

        // Check if the new position is within the bounds
        if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h) {
            // Check if there's any overlapping with other creatures
            bool overlap = false;
            for (auto& other : speciesInfo) {
                if (&info != &other && new_x == other.xCoordinate && new_y == other.yCoordinate) {
                    if ((info.title == "herbivore" && other.title == "herbivore") || 
                        (info.title == "omnivore" && other.title == "omnivore")) {
                        overlap = true; // Overlapping with other creatures is not allowed
                        break;
                    }
                    if (other.title == "plant" && other.energy + info.energy > info.max_energy) {
                        overlap = true; // Consumption of plants that make energy go over max is not allowed
                        break;
                    }
                }
            }
            // If no overlap, at least one direction is legal
            if (!overlap) {
                can_move = true;
                break;
            }
        }
    }
    // Return true only if at least one movement direction is legal
    return can_move;
}

//main method for determining animal movement
void animalMovement(std::vector<SpeciesInfo>& speciesInfo, int w, int h, std::vector<deadPlants>& deadPlants) {
    bool canI;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(speciesInfo.begin(), speciesInfo.end(), g);
    for (auto& info : speciesInfo) {
        int current_x = info.xCoordinate;
        int current_y = info.yCoordinate;
        //std::cout << info.character << " at (" << info.xCoordinate << ", " << info.yCoordinate << ")" << std::endl;
        //std::cout << info.title << std::endl;
        canI = canIMove(speciesInfo, info, w, h);
        if (!canI) {
            //skip this unmovable animal
            //std::cout << info.character  << " can't move" << std::endl;
            continue;
        } else {
            bool incentive;
            incentive = isThereIncentive(speciesInfo, info);
            if (incentive) {
                incentiveMovement(speciesInfo, info, w, h, deadPlants);
            } else {
                randomMovement(speciesInfo, info, w, h);
                //std::cout << "return to animal movement: xC is " << info.xCoordinate << " and yC is " << info.yCoordinate << std::endl;
            }
        }
        if (info.energy <= 0) {
            // Remove the element from speciesInfo directly
            //std::cout << info.character << " has died of starvation! RIP" << std::endl;
            speciesInfo.erase(std::remove(speciesInfo.begin(), speciesInfo.end(), info), speciesInfo.end());
        }
        if (current_x != info.xCoordinate || current_y != info.yCoordinate) {
            //std::cout << "I moved!" << std::endl;
        } else {
            //std::cout << "I did not move." << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
}

//main method for each iteration of the simulation
void iteration(std::vector<SpeciesInfo>& speciesInfo, int w, int h, std::vector<deadPlants>& deadPlants) {
    //plant regrowth logic
    plantRegrow(deadPlants, speciesInfo);
    //random movement between herbivore and carnivore
    animalMovement(speciesInfo, w, h, deadPlants);
}

//menu to choose what to see/do
void miniMain(std::vector<SpeciesInfo>& speciesInfo, Map map, std::string speciesInput, int w, int h, std::vector<deadPlants>& deadPlants) {
    int answer;
    while (answer != 3) {
        answer = welcomeMessage();
        std::cout << "\n" << std::endl;
        if (answer == 4) {
            mapSize(map);//check the map dimensions
        }
        else if (answer == 5) {
            basicSpeciesTest(speciesInput);//check the species list
        }
        else if (answer == 6) {
            printSpeciesInfo(speciesInfo);//check the details of all organisms on the map
        }
        else if (answer == 7) {
            map.mapPrinter(speciesInfo, map.getWidth(), map.getHeight());//print the current map
        }
        else if (answer == 1) {
            iteration(speciesInfo, w, h, deadPlants);
            map.mapPrinter(speciesInfo, map.getWidth(), map.getHeight());//run an iteration
        }
        else if (answer == 2) {
            int input;
            input = getAnyIntInput();
            for (int i=0; i < input; i++) {
                iteration(speciesInfo, w, h, deadPlants);//run a batch iteration i times
                map.mapPrinter(speciesInfo, map.getWidth(), map.getHeight());
                std::cout << "-------------------------------" << std::endl;
            }
        }
        else if (answer == 111) {//EXTRA CREDIT
            // Check if there are any available characters
            bool charactersAvailable = false;
            for (char ch = 'A'; ch <= 'Z'; ++ch) {
                if (std::find_if(speciesInfo.begin(), speciesInfo.end(),
                                [ch](const SpeciesInfo& info) { return info.character == ch; }) == speciesInfo.end()) {
                    charactersAvailable = true;
                    break;
                }
            }
            if (charactersAvailable) {
                auto emptySpot = spotFinder(map, speciesInfo);
                if (std::get<0>(emptySpot) != -1 && std::get<1>(emptySpot) != -1) {
                    speciesMaker(speciesInfo, w, h, map);
                    map.mapPrinter(speciesInfo, map.getWidth(), map.getHeight());
                } else {
                    std::cout << "No empty spots on map." << std::endl;
                }
            } else {
                std::cout << "All characters are already in use. No new species can be created." << std::endl;
            }
        }
        std::cout << "\n" << std::endl;
    }
    std::cout << "Goodbye!" << "\n" << std::endl;//input is 7. End the simulation
}

//sets up the simulation
int main(int argc, char* argv[]) {

    std::string mapInput = argv[1];// read in the map input
    std::string speciesInput = argv[2];// read in the species input
    std::vector<std::tuple<int, int, char>> organismList;
    Map map = mapMaker(mapInput);//make a map object
    organismList = mapOrganisms(map);//create a list of organisms on the map
    int W;
    int H;
    W = mapW(map);//record the width
    H = mapH(map);//record the height

    //basicSpeciesTest(speciesInput);
    //map.mapPrinter(organismList, map.getWidth(), map.getHeight());

    std::vector<SpeciesInfo> speciesInfo;
    std::vector<deadPlants> deadPlants;
    setup setup;
    speciesInfo = setup.starter(mapInput, speciesInput);//setup a vector of the organisms on the map

    miniMain(speciesInfo, map, speciesInput, W, H, deadPlants);

    return 0;
}