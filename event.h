#include "playerMove.h"


void handleRandomEvent(int* hp, int* treasures);
void exploreRoom(int* hp, int* treasures);




void handleRandomEvent(int* hp, int* treasures) {
    int event = getRandomNumber(1, 10);

    switch (event) {
        case 1:
            printf("You find a healing potion! +20 HP.\n");
            *hp += 20;
            break;
        case 2:
            printf("Uh-oh! You encounter a trap! -30 HP.\n");
            *hp -= 30;
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

    if (event <= 20) {
        event = 1;
    } else if (event <= 80) {
        event = 2;
    } else if (event <= 90) {
        event = 3;
    } else {
        event = 4;
    }

    switch (event) {
        case 1:
            printf("You find nothing of interest in this room.\n");
            break;
        case 2:
            printf("You find a better sword +5 attack!\n");
            attack += 5;
            break;
        case 3:
            printf("Congratulations! You discover a treasure in this room! +1 treasure.\n");
            *treasures += 1;
            break;
        case 4:
            printf("You find a big healing potion! +40 HP.\n");
            *hp += 40;
            break;
        default:
            break;
    }
}




