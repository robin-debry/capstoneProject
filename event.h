#include "playerMove.h"

int getRandomNumber(int min, int max);
void handleRandomEvent(int* hp, int* treasures);
void exploreRoom(int* hp, int* treasures);
void fightEnemy(int* hp);


int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void handleRandomEvent(int* hp, int* treasures) {
    int event = getRandomNumber(1, 10);

    switch (event) {
        case 1:
            printf("You find a healing potion! +20 HP.\n");
            *hp += 20;
            break;
        case 2:
            printf("Uh-oh! You encounter a trap! -40 HP.\n");
            *hp -= 40;
            break;
        case 3:
            printf("A friendly creature gives you a treasure! +1 treasure.\n");
            *treasures += 1;
            break;
        default:
            break;
    }
}


void exploreRoom(int* hp, int* treasures) {
    int event = getRandomNumber(1, 100);
    if (event <= 70) {
        event = 1;
    } else if (event <= 90) {
        event = 2;
    } else {
        event = 3;
    }

    switch (event) {
        case 1:
            printf("You find nothing of interest in this room.\n");
            break;
        case 2:
            printf("You encounter an enemy! Prepare for a fight!\n");
            fightEnemy(hp);
            break;
        case 3:
            printf("Congratulations! You discover a treasure in this room! +1 treasure.\n");
            *treasures += 1;
            break;
        default:
            break;
    }
}


void fightEnemy(int* hp) {
    int enemyHP = getRandomNumber(10, 30);

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
                enemyHP -= getRandomNumber(5, 15);
                break;
            case 2:
                // 50% chance to successfully run away
                if (getRandomNumber(1, 2) == 1) {
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
        printf("You were defeated by the enemy. -10 HP.\n");
        *hp -= 10;
    }
}

