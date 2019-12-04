//
// Unit test for bug number 2.
// Mine card logic error.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int failed = 0;

void localassert(int b, char* msg) {
    if (!b) {
        printf("ASSERTION FAILURE: %s\n",msg);
        failed = 1;
    }
}

void checkasserts() {
    if (!failed) {
        printf ("TEST COMPLETE.\n");
    }
}

int main(int argc, char const *argv[]){

    int r, i;
    int j = 0;
    struct gameState G;
    srand((int)argv[1]);

    for (i = 0; i < 2000; i++) {
        int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
        r = initializeGame((rand() % MAX_PLAYERS), k, rand(), &G);
        //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
        r = cardEffect(mine, (rand() % 3), gold, -1, &G, 0, &j);
        localassert(r == 0, "Bug 2 Failed correctly");

        if(failed) {
            break;
        }
    }

    checkasserts();
    return 0;
}