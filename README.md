# capstoneProject

## Game Description

This is a text based console game in C. The game is called "Lost in the Labyrinth". The player is lost in a labyrinth and has to find the exit or find all treasures to win. The labyrinth is a 20x20 grid of rooms. The player can move in four directions (up, down, left, right). The player has a limited amount of HP. The player can also find traps that will reduce their HP. The player can also find teleport rooms that will teleport them to a random room. The player can also find doors that cannot be opened. The player can save the game and load it later.

## How to play

### Compile

To compile the game, run the following command:

```bash
gcc -o main main.c
```

### Run

To run the game, run the following command:

```bash
./main
```

### Game commands

The game commands are explain inside the game but here is a list of them:

1. Move
2. Explore
3. Save and quit
4. Quit without saving

inside move, you can move in four directions (up, down, left, right)

1. Up
2. Down
3. Left
4. Right

## Win Conditions

The player wins if they reach the exit or if they find all treasures.

## Lose Conditions

The player loses if they run out of HP.

## Map

The map is a 20x20 grid of rooms.The map is randomly generated at the start of the game exept the start and end of the map.
