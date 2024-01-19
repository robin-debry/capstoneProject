# include "display.h"

int isValidMove(int x, int y);
void movePlayer(int* x, int* y, char map[SIZE][SIZE]);
void clearTerminal();
void fightEnemy(int* hp);
int getRandomNumber(int min, int max);


int wallHits[MAX_WALLS][2]; // Assuming a maximum of 100 walls
int numWallHits = 0;
int playerY = 0, playerX = 0;
int hp = MAX_HP;
int attack = 7;
int treasures = 0;
int wallAlreadyHit = 0;

void clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
    system("clear");
    #endif
}

int isValidMove(int x, int y){
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int isValidMoveWall(int x, int y, char map[SIZE][SIZE]) {
    return map[x][y] != '#';
}


int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void movePlayer(int* x, int* y, char map[SIZE][SIZE]) {
    int newX, newY;
    printf("Enter the direction to move (1. Up, 2. Down, 3. Left, 4. Right):\n");
    int direction;
    
    while (1) {
        if (scanf("%d", &direction) == 1) {
            clearTerminal();
            break;
        } else {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }
    }

    switch (direction) {
        case 1:
            newX = *x - 1;
            newY = *y;
            break;
        case 2:
            newX = *x + 1;
            newY = *y;
            break;
        case 3:
            newX = *x;
            newY = *y - 1;
            break;
        case 4:
            newX = *x;
            newY = *y + 1;
            break;
        default:
            printf("Invalid direction. Please choose again.\n");
            return;
    }

    if (isValidMove(newX, newY)) {
        if (!isValidMoveWall(newX, newY, map)) {
            printf("Invalid move. You cannot go through walls.\n");

            for (int i = 0; i < numWallHits; i++) {
                if (wallHits[i][0] == newX && wallHits[i][1] == newY) {
                    wallAlreadyHit = 1;
                    break;
                }
            }

            // If the wall has not been hit before, record it
            if (!wallAlreadyHit && numWallHits < MAX_WALLS) {
                wallHits[numWallHits][0] = newX;
                wallHits[numWallHits][1] = newY;
                numWallHits++;
            }
            return;
        }

        if (!visited[newX][newY]) {
            visited[newX][newY] = 1; // Mark the room as visited

            if (map[newX][newY] == 'E') {
                printf("You encounter an enemy! Prepare for a fight!\n");
                fightEnemy(&hp);
            } else if (map[newX][newY] == 'T') {
                printf("You found a treasure!\n");
                treasures++;
            }
        }

        *x = newX;
        *y = newY;
    } else {
        printf("Invalid move. You cannot go outside the labyrinth.\n");
    }
}


void fightEnemy(int* hp) {
    int enemyHP = getRandomNumber(20, 50);

    while (*hp > 0 && enemyHP > 0) {
        printf("Your HP: %d | Enemy HP: %d\n", *hp, enemyHP);
        printf("Choose an action: 1. Attack | 2. Run away\n");

        int choice;
        while (1) {
            if (scanf("%d", &choice) == 1) {
                break;  // Input is a valid integer
            } else {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');  // Clear input buffer
            }
        }


        switch (choice) {
            case 1:
                // Simulate attack
                enemyHP -= attack;
                if (enemyHP > 0) {
                    printf("You attack the enemy!\nYou deal %d damage!\nThe enemy's HP is now %d.\n",attack, enemyHP);
                    *hp -= getRandomNumber(10, 20);
                    
                    printf("The enemy attacks! Your HP is now %d.\n", *hp);
                    break;
                }
                else {
                    printf("You attack the enemy! The enemy's HP is now 0.\n");
                    break;
                }
        
                break;
            case 2:
                if (getRandomNumber(1, 50) <= 15) {
                    printf("You successfully run away!\n");
                    return;
                } else {
                    printf("Failed to run away! The enemy attacks!\n");
                    *hp -= getRandomNumber(10, 20);
                }
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    if (*hp > 0) {
        printf("You defeated the enemy!\n");
    } else {
        printf("You were defeated by the enemy !\n");
    }
}