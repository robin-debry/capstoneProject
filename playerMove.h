# include "display.h"

int isValidMove(int x, int y);
void movePlayer(int* x, int* y, char map[SIZE][SIZE]);
void clearTerminal();


void clearTerminal(){
    system("clear");
}

int isValidMove(int x, int y){
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int isValidMoveWall(int x, int y, char map[SIZE][SIZE]) {
    return map[x][y] != '#';
}


void movePlayer(int* x, int* y, char map[SIZE][SIZE]) {
    int newX, newY;
    printf("Enter the direction to move (1. Up, 2. Down, 3. Left, 4. Right):\n");
    int direction;
    while(1) {
        if (scanf("%d", &direction) == 1) {
            clearTerminal();
            break;  // Input is a valid integer
        } else {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear invalid input from buffer
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
            return;
        }
        *x = newX;
        *y = newY;

        visited[*x][*y] = 1;
    } else {
        printf("Invalid move. You cannot go outside the labyrinth.\n");
    }

    
}

