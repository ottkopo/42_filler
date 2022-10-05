# 42_filler
Hive Helsinki project Filler with visualizer made with Pygame

Filler is a project where 2 players take turns placing randomly generated pieces on the board with the goal of placing as many pieces as possible. Failing to place a piece on your turn will end the game for you, and you will have to wait until the opponent is also unable to place a piece for the game to be finished. Succesfully placing a piece will give 1 point no matter the size of the piece. The goal of this project was to _create an algorithm to play the game against pre-created players using the given virtual machine to run the game_, not to create a program to run this game.

_NOTE: Everything in the 'recources' folder is provided by the school Hive Helsinki, and is **NOT** code written by me. It is only used in this project for testing my own program against other programs designed to play the same game._

**How to run in the terminal:**
1. Clone the repository
2. Use the command 'make' in the root of the repository to create executable for okoponen.filler
3. Go to 'tests' folder
4. Run the command './run_game.sh' to run the game in the terminal.
4.5. You can also modify the 'run_game.sh' file. You can change the opposing player from carli.filler to any player located in the resources/players folder. There are also 3 maps of different sizes provided in the resources/maps folder.

**How to run with visualizer:**
1. Clone the repository
2. Use the command 'make' in the root of the repository to create executable for okoponen.filler
3. Go to 'tests' folder
4. Run the commant './visualizer_run.sh' (NOTE: you need to have pygame installed on your machine for this to work, running the command 'pip install pygame' will install it for you if you need it)
5. The visualizer will open a new window, and you need to press space to start the visualizer.
6. Visualizer has a couple of different keyboard functionalities:
      - pressing 'space' will pause/unpause the game
      - pressing 'right arrow key' will speed up the game
      - pressing 'left arrow key' will slow down the game
      - pressing 'esc' will end the program
7. Visualizer will print different info in the terminal while the game is running, such as which player is which color, and the points for each player once the game has finished.


**My approach and the algorithm**

I took a heatmap approach to this project, where I would create a 2D matrix of the map, and fill every cell of the map with a value determining how far the given cell is from the opponents piece. Then I would just check every valid placement for the given piece and save the one with the lowest sum of covered cells in that placement. This approach proved quite strong against the given opponents, since they are actually quite weak players, but I did also have quite a bit of success playing against other algorithms created by other students of Hive Helsinki.

**Visualizer**

The visualizer was a bonus for this project, so I was not required to make one to pass this project. However I had never used python so I took it as a learning opportunity to learn the basics of a new language. The Visualizer could definitely be improved, but I also didn't want to spend too much time on it because I need to also advance in my studies. I am however quite happy that I decided to make a visualizer for this project since it makes it much easier to see how the algorithms fight compared to the terminal input. 
