#include "event.h"


typedef struct GS{
    int playerX;
    int playerY;
    int hp;
    int attack;
    int treasures;
    int visited[SIZE][SIZE];
    int wallHits[MAX_WALLS][2];
    int numWallHits;
} GameState;

void saveGame(const char *filename, GameState *state) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(state, sizeof(GameState), 1, file);

    fclose(file);
}


void loadGame(const char *filename, GameState *state) {
    FILE *file = fopen(filename, "rb");
    printf("Loading game... previous game\n");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    fread(state, sizeof(GameState), 1, file);

    printf("Welcome back!\n");

    fclose(file);
}