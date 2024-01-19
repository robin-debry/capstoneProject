
#include "saveGame.h"

// Main function
int main() {
    
    

    GameState *gameState = (GameState *)malloc(sizeof(GameState));

    // Check if malloc was successful
    if (gameState == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }


    FILE *saveFile = fopen("savegame.dat", "rb");
    if (saveFile == NULL) {
        printf("No previous game found.\n");
        printf("Starting a new game...\n");
    } else {
    
        
        loadGame(saveFile, gameState);
        fclose(saveFile);
    }

    char map[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 50% chance for an empty room, 15% chance for a wall, 35% chance for a special room
            int roomType = getRandomNumber(1, 100);
            if (roomType <= 50) {
                map[i][j] = '.';
            } else if (roomType <= 65) {
                map[i][j] = '#'; // # for wall
            } else {
                map[i][j] = getRandomNumber(1, 2) == 1 ? 'T' : 'E'; // T for treasure, E for enemy
            }
        }
    }


    printInstructions();

    while (1) {
        printMap(map, playerY, playerX, visited, wallHits, numWallHits);
        printStats(hp, treasures);

        int choice;
        printf("\nChoose an action:\n");
        printf("1. Move\n2. Explore\n3. Save and Quit\n4. Quit without saving\n");
        while (1) {
            if (scanf("%d", &choice) == 1) {
                break;  // Input is a valid integer
            } else {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');  // Clear invalid input from buffer

            }
        }
        switch (choice) {
            case 1:
                movePlayer(&playerY, &playerX, map);
                visited[playerY][playerX] = 1;
                break;
            case 2:
                exploreRoom(&hp, &treasures);
                break;
           case 3:
                printf("Saving the game...\n");
                saveGame("savegame.dat", gameState);
                printf("Game saved. See you next time!\n");
                free(gameState); // Release allocated memory
                return 0;

            case 4:
                printf("Quitting the game. See you next time!\n");
                free(gameState); // Release allocated memory
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }

        handleRandomEvent(&hp, &treasures);

        if (hp <= 0) {
            displayOutcome(0); 
            break;
        }

        if (playerY == SIZE - 1 && playerX== SIZE - 1) {
            displayOutcome(1);  
            break;
        }

        if (treasures == MAX_TREASURES) {
            displayOutcome(2);  
            break;
        }
    }

    return 0;
}
