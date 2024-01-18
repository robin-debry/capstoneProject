#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX_HP 100
#define MAX_TREASURES 25

void printInstructions();
void printMap(char map[SIZE][SIZE], int playerX, int playerY);
void printStats(int hp, int treasures);
void displayOutcome(int result);

void printInstructions() {
    printf("\nInstructions:\n");
    printf("-------------\n");
    printf("\nWelcome to Lost in the Labyrinth!\n");
    printf("You find yourself in a mysterious labyrinth.\nYour goal is to reach the exit or collect all treasures.\n");
    printf("Be cautious! There are dangers and dead ends in the labyrinth.\n");
    printf("You have a limited amount of HP, and your inventory can only hold a certain number of treasures.\n");
    printf("Good luck!\n\n");
}

// Function to print the game map
void printMap(char map[SIZE][SIZE], int playerX, int playerY) {
    printf("Current Map:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");  // Player's current position
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

// Function to print player stats
void printStats(int hp, int treasures) {
    printf("Player Stats:\n");
    printf("------------------------\n");
    printf("HP: %d/%d\n", hp, MAX_HP);
    printf("------------------------\n");
    printf("Treasures collected: %d/%d\n", treasures, MAX_TREASURES);
}

// Function to display game outcome
void displayOutcome(int result) {
    switch (result) {
        case 0:
            printf("Game over! You ran out of HP. Better luck next time!\n");
            break;
        case 1:
            printf("Congratulations! You reached the exit and won the game!\n");
            break;
        case 2:
            printf("Congratulations! You collected all treasures and won the game!\n");
            break;
        default:
            break;
    }
}
