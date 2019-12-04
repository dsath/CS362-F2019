//
// Random test for bug number 9.
// Unit test for tribute card
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void localassert(int i, int j, int *error, char *message)
{
    printf("TEST %d FAILED - %s\n", *error, message);
    *error = *error+1;
}

void localtribute(struct gameState *post)
{
    int i, pc;
    int error = 1;
    int currentPlayer = 0;
    int nextPlayer = 1;
    struct gameState G;
    memcpy (&G, post, sizeof(struct gameState));

    for (i = 0; i < 6; ++i) {
        drawCard(currentPlayer, post);
    }
    cardEffect(tribute, 0,0,0, post, 0, 0);
    localassert(post->coins, G.coins + 2, &error, "Coins supposed to increase by 2.");
}

int main()
{
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    int players = 2;
    int seed = 100;
    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(players, k, seed, &G);
    localtribute(&G);
    exit(0);
}