#include "event.h"

// Structure to hold the game state
typedef struct {
    int playerX;
    int playerY;
    int hp;
    int attack;
    int treasures;
    int visited[SIZE][SIZE];
    int wallHits[MAX_WALLS][2];
    int numWallHits;
} GameState;

// Function to save the game state to a file
void saveGame(const char *filename, GameState *state) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    // Write the entire game state to the file
    fwrite(state, sizeof(GameState), 1, file);

    fclose(file);
}

// Function to load the game state from a file
void loadGame(const char *filename, GameState *state) {
    FILE *file = fopen(filename, "rb");
    printf("Loading game... previous game\n");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Read the entire game state from the file
    fread(state, sizeof(GameState), 1, file);

    printf("Welcome back!\n");

    fclose(file);
}
