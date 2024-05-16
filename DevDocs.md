### General Information

This explains the general process of my code.
I will explain the functionality in sequential order, based on the order of steps.

## Simulation Functionality

**main()** First, the main function in main.cpp is called.
It takes in two arguments (other than ecosystem.bin) and creates string variable for the names of these files.
These two files are the map and species files.
It also intializes a vector organimsList which will store the characters (and their x, y coordinates) of organisms on the map.

A map object is created using the map classes method "mapMaker". Next, the organismList vector is filled out using the map variable. Finally, the width and height of the map are stored using functions that count the number of spaces per line and the number of lines.

Next, two more vectors are intialized, speciesInfo and deadPlants.
speciesInfo is the main data structure that stores all data relevant to the organisms.
It's data structure is stores in speciesInfo.h
deadPlants is a lot less present.
When a plant dies, its data is first added to this vector along with a regrowth counter.
Each iteration, it checks to see if the plant has reached its regrowth coefficient, and, if it has (and there are no animals occupying its spot), it is removed from from this vector and readded to speciesInfo.

Main method's final purpose is to run a setup of the game.
It runs a method "starter" which is part of the setup class and this method creates vectors of the map organisms and the species list, and then runs a method "matchmaker" that matches a map character with an organism from the list.
"Matchmaker" is a method of the matchmaker class.
If there is no match, then the organism is simply not included in the simulation.
It then returns the speciesInfo vector to main.

Main then hands the reins to the method "miniMain" by passing in the arguments of the speciesInfo vector, the map, speciesInput, the map width, the map height, and the deadPlants vector.

From here on out, I will mention if a method is located outside main. Otherwise assume it is in main.

**miniMain()** miniMain()'s main purpose is to present the user with a menu after each command. A welcome message is displayed, which says "Welcome to the Simulation" along with a list of what inputs 1, 2, and 3 will do. The user then inputs a number 1 through 7. Any other input results in the menu asking for a number 1 through 7 again. Inputs 4 through 7 are extra inputs for the devloper and are not specifically told to the user.

Here are what inputs 4, 5, 6, 7, and 3 do. 4 will simply print out the map dimensions. This is available since it may not be immediately obvious to the user what the dimensions are if there are not orgnaisms populating the lowest rows or furtherst collumns. 5 prints out the list of organism types from the species.txt file. This is the only time the speciesInput file is used in miniMain or the methods it calls, and the method that does this is located in matchmaker.cpp. 6 prints out the character, type, x coordinate, y coordinate, max energy, and current energy for all animals on the map. 7 prints out the map with the current state of the simulation, and this uses a method in map.h. 4 simply exits the simulation.

Inputs 1 and 2 run a single iteration and a batch of iterations respectively. For 1, it prompts the user to input an integer, and then that many interations are performed (the map is printed out each time with a sperator "---"). 2 runs a single iteration and prints out the map of the result.

**iteration()** The iteration method has two steps. First, it checks if any plants are able to regrow, and does so if possible. It then calls the animalMovement method.

**animalMovement()** The animalMovement method calls the following functions within it: canIMove(), isThereIncentive(), incentiveMovement(), randomMovement(). The order in which organisms are considered is randomized. After these, we check if the animal has run out of energy and, if so, it dies and is removed from the speciesInfo vector. I will now explain how the logic works by explaining how an organism's movement is considered.

**canIMove()** First, we consider if the organism can move at all. If it is a plant, or is stuck, it can't move and it moves on to the next organism.

**isThereIncentive()** Next, we check if the animal (all plants have been skipped from canIMove()) has an incentive. For herbivores, plants and omnivores are incentives. For omnivores, plants and herbivores are incentives. If there is a an incentive, incentiveMovement() is called. If not, randomMovement() is called.

**incentiveMovement()** This method is called if there is an incentive for the animal to move a certain way. For herbivores, they first make sure they move in the opposite direction from omnivores. However, if this move is not possible, it then essentially ignores the omnivore. It then checks for plants nearby. If there is one, and it can eat it without going over its max energy, it moves to eat it. If not, it then moves randomly.

For omnivores, it does not care about the order in which it chooses herbivores or plants. It will eat a random target, if it can without going over its max energy. If it is unable to eat any of its targets, then it will move randomly.

**randomMovement()** This method simply makes an animal move in a random direction: up, down, left, or right.

This has covered the basic process in which the simulation is run.

## Additional Explanation of Methods

I will now give an explaination of the methods that were not discussed in detail previously.

### Other main.cpp methods

**removeElement()** This method removes an organism from the speciesInfo vector. It first checks if it is a plant, and if so, saves its information to the deadPlants vector. It then removes the organism from speciesInfo.

**plantRegrow()** This method is what makes plants regrow. It increases a value "regrow factor" each iteration until it reaches the regrowth coefficient of the plant. Once that happens, the plant regrows in the spot it was eaten. However, if an animal is occupying its spot, then it must wait until its spot is open.

**revivePlant()** This method is called by plantRegrow(). It removes the plant entry from the deadPlants vector and adds it back into the speciesInfo vector.

**printSpeciesInfo()** This is the method called by input 3 of the miniMain()'s menu. It prints out the information for all animals on the map.

**welcomeMessage()** This methods prints the menu so that users can know what input options they have.

**getAnyIntInput()** This method takes an input from the user and accepts any integer greater than zero. This is used for running a batch of iterations.

**getIntInput()** This method takes an input from the user and accepts any integer from 1 to 7. This is used for operating the menu in miniMain().

**basicSpeciesTest()** This method calls the printSpecies() method in matchmaker.cpp. It is called by input 2 of the miniMain()'s menu.

**mapOrganisms()** This method returns a list of organisms on the map by their coordinates and their character. It called by main() and uses map.h's method "findOrganisms()".

**mapSize()** This method prints the width and height of the map. It is called by input 1 of the miniMain()'s menu.

**mapW()** This method returns the width of the map.

**mapH()** This method returns the height of the map.

**mapMaker()** This method creates a map object based on the map.txt inputed. It is called by main().

### main.cpp notable libraries

**algorithm library** This library is implemented in the following ways: It is used to find a specific entry in my vectors. It is used to shuffle the order of lists for random movement. It is used to remove an entry from a vector.

**random library** This library is used to generate random numbers for list shuffling.

### getSpecies.h and getSpecies.cpp

**readSpecies()** This method takes in the species.txt file and returns a vector of the species information from it. It is called by printSpecies() in matchmaker.cpp and by starter() in setup.cpp.

### matchmaker.h and matchmaker.cpp

**printSpecies()** This method prints out the species from the species.txt file. It is called by basicSpeciesTest() in main.cpp.

**love()** This method pairs up characters on the map with species from the species list. It is called by starter() in setup.cpp.

### setup.cpp

**starer()** This method saves the map data (characters and their coordinates), the species data, and then calls love() on these vectors to pair them up. love() then returns the data as a SpeciesInfo vector. It returns this vector. This method is called by main().

### speciesInfo.h

This is where my speciesInfo vector information is stored. It is the main location of all my species data, including their title (example: "plant"), their character (example: "a"), their energy, their max energy, their regrowth coefficient, their x coordinate, and their y coordinate. It also defines an operator== for the class which is used when finding a speicific organism in the vector to delete it.

### plantSaves.h

This is where the dead plants' data is stored. It is fairly similar to speciesInfo.h, but is only used when a plant has died and is waiting to regrow. The main difference is it also has a 'current regrowth' value that stores how many interations the plant has been waiting to regrow.

### MakeFile

*I have a MakeFile that operate on three commands: "make", "make clean", and "make sample". "make" creates the .o and .bin files needed for the simulation and then the user must input specifically the map and species files they want to use with "./ecosystem.bin targetMap.txt targetSpecies.txt". "make clean" removes all the .o and .bin files that were created for the simulation execution. "make sample" runs the simulation specifically for map.txt and species.txt.*

### map.h

**readMap()** This method takes in the map.txt file and makes the map object usable for other methods in the program. It is called by mapMaker() in main.cpp and starter() in setup.cpp.

**findOrganisms()** This method looks through the current map to see if there are any characters on the map. If so, it records the character and its coordinates and adds them to a vector. It then returns this vector. It called by mapOrganisms() in main.cpp and starter() in setup.cpp.

**printOrganisms()** This method prints the location of each organism on the map. It is currently not used since the information from this method is included in printSpeciesInfo() in main.cpp. It has been kept in for possible further use.

**mapPrinter()** This method prints out the current state of the map. It is called by miniMain() in main.cpp.

**getWidth()** This method returns the width of the map. It is called by getW() and miniMain() in main.cpp.

**getHight()** This method returns the height of the map. It is called by getH() and miniMain() in main.cpp.

**getFilename()** This method returns the filename of the map input file. It is currently not used. It has been kept in for possible further use.

## Input Files

There are various maps included in the input folder, along with an additional species list. The additional species list was to ensure different species inputs worked. The map files generally were to test specific conditions. For exmaple, sadAnimalMap.txt was to test if an animal with no movement behaved correctly (not moving, not crashing the simulation, etc.).

map.txt and species.txt are the 'base' input files. They were most commonly tested on.

map2.txt allowed for testing on a large map with many organisms to consider.

## Other Files

**README.md** This is a text file for users. It explains how to run the simulation in an easy-to-understand way.

**Spec.md** This file was given by the instructor who created this assignment. It gives the specific instructions on how this simulation is to operate.

**DevDocs.md** This is the file you are reading right now. It gives a developer-level description of my simulation code.

**.gitignore** This file instructs github to ignore certain files. This is to make the code on my remote repository more streamlined by just including the necessary files.

## Extra Credit

The following methods are specifically for the extra credit I created.

**speciesMaker()** This method allows the user to create their own species and add it to the map. It is accessed from miniMain() by typing '111' into the input bar. If there is no space on the map, or if there are no characters left to name the species, it does not get called. In the method, there are various messages that make this a fun experience for the user. It collects the following information from the user: whether the species is a plant, herbivore, or omnivore, the energy points, the regrowth factor (if it's a plant), the x and y coordinates, and the character/name of the species. It is then added to the SpeciesInfo vector and becomes a part of the simulation.

**getCharacterInput()** This method prompts the user to enter a single character. This is used when naming the new species.

**spotFinder()** This method looks through the map to find an empty spot. It serves two purposes. One, it ensures there is an empty spot. If not, this extra credit cannot be accessed. Two, it finds an empty spot to tell the user when they need to input an x and y coordinate so they have an easy choice.

**getCoordInput()** This method is very similar to my other user input methods. It's difference is that it allows for a zero as an input.

**getMakerInput()** This method is very similar to my other user input methods. It's difference is it only allows 1, 2, or 3 as inputs. This correlates to the user choosing a plant, herbivore, or omnivore as its species.

**limits library** This library is used in my extra credit. This is used in the getCharacterInput() method and is used to make sure the input is a single character.