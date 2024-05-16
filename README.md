## README for the User

Hello! Welcome to my simulation of a ecological system.

In this simulation, you can run 'iterations' of a simulation.
Each iteration, animals move around.
Some animals are herbivores, some are omnivores.
Both eat plants, but omnivores can also eat herbivores.
Once an animal is eaten, it dies.
However, after plants die, the regrow after a certain amount of time!
Animals also can die if they go too many iterations without eating.
That's the basics!

This is how you run my simulation:
Using the command prompt on your devie, make your way to my "src" folder.
This is done by typing "cd path_to_src/src/".
Of course, please replace path_to_src with the actual file path.
For example, this may be "cd Desktop/project/src/".
Next, input "make sample".
And you're in the game!
You should see a menu that gives you options.
If there are other maps or species lists you want to use, that's ok!
Instead of "make sample", type in "make".
Next, type in "./ecosystem.bin targetMap.txt targetSpecies.txt".
Replace targetMap.txt and targetSpecies.txt with the files you want to load in.

I hope you enjoy my simulation!


### Extra Credit

I have included a "species maker" feature that allows the user to make a custom species. This is accessed by typing '111' into the input menu. The details of how it works are written in DevDocs.