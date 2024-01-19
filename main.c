
#include "event.h"

// Main function
int main() {

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
        printf("1. Move\n2. Explore\n3. Quit\n");
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
                printf("Quitting the game. See you next time!\n");
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
