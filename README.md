# Ataxx
Ataxx is an arcade game that came out in 1990. This is an implementation of this old game in C++ using the Qt framework.

## Getting Started
This Ataxx game has two available arguments. You can use '--help' to see the different options and the corresponding arguments.

The graphical mode is easily understandable as you just play the game intuitively with the usual Ataxx rules. However, the console mode is detailed below.

###Rules
The game includes two pawn colors (red and blue) and a 7x7 grid.
We start from an initial configuration where a certain number of pawns are already placed (in the 4 corners of the grid).
The players take turns and are forced to move one of their pieces.

The allowed shots are:
* Place a new piece next to one of its pieces (in one of the 8 adjacent squares, if it is empty).
* Make "jump" one of his pieces, that is to say move it to one of the empty squares located at 2 displacements (diagonals included) of the initial position.
This allows you to go over enemy pieces.

After a hit, all neighboring pieces in the destination box become the color of the player just played.
The game ends when one of the two players can no longer make a move.
The player with the most pieces wins the game (draws are possible).

To play, the player must first select the pawn to play.
The possible shots are then displayed on the grid.
If the player selects one of the possible moves, the shot is made and we go to next turn.

### Console Mode
In console mode you have to select a pawn by its coordinates.
Coordinates go from 0 to 6.
You have to separate the two coordinates by a space, and then press enter.

When your pawn is selected, the available moves are displayed.
Select coordinates from the available positions and enter them in the console.
If the coordinates are valid the action corresponding (move/add) will be applied.

The board and the number of pawn for each player is displayed at each turn.
Players each play their tricks.

If you enter "exit" in the console you can exit the game.
If you enter "restart" in the console you lose your game and another one is launched.
Any other input is invalid.


### Installing
Download the zip file from [Github](https://github.com/adrienls/Ataxx)
```
wget --no-cookies https://github.com/adrienls/Ataxx/archive/master.zip -O Ataxx-master.zip
```

Unzip the folder
```
unzip ./Ataxx-master.zip
```

Compile the project for your system using the [CMakeLists.txt](CMakeLists.txt) available

Launch the ./Ataxx file

## Built With
* [Qt](https://www.qt.io/) - Qt is a cross-platform application framework and widget toolkit for creating classic and embedded graphical user interfaces.

* [termcolor](https://github.com/ikalnytskyi/termcolor) - Termcolor is a header-only C++ library for printing colored messages to the terminal.

* [getopt](https://www.gnu.org/software/libc/manual/html_node/Getopt.html) - The getopt and getopt_long functions automate some of the chore involved in parsing typical unix command line options.

## Versioning
We use [Git](https://git-scm.com/) for versioning.

## Authors
* [adrienls](https://github.com/adrienls)

## License
This project is licensed under the GNU AGPLv3 License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
This game is the final Qt project of my second year of engineering school in France.