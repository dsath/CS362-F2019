///////////////////////////////////////////
// Baron Unit Tests
//////////////////////////////////////////


//int baron_func(struct gameState *state, int currentPlayer, int choice1);

#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int ambassador_func_test(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2); 
int main() {
int k[10] = { adventurer, council_room, feast, gardens, mine
, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int
	coppers[MAX_HAND];
	int
	silvers[MAX_HAND];
	int
	golds[MAX_HAND];
	memset(&G, 0, sizeof(struct gameState));
	initializeGame(2, k, 5, &G);
	G.handCount[0] = 5;
	memcpy(G.hand[0], coppers, sizeof(int) * 5);
	ambassador_func_test(&G, 0, 0, 1, 0);
	ambassador_func_test(&G, 0, 0, 0, 1);
	ambassador_func_test(&G, 0, 3, 0, 1);

	return 0;
}

int ambassador_func_test(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2) {
        int j = 0;		//used to check if player has enough cards to discard
	int i = 0;

        if (choice2 > 2 || choice2 < 0)
        {
            return -1;
        }

        if (choice1 == handPos + 1)
        {
            return -1;
        }

        for (i = 0; i < state->handCount[currentPlayer]; i++)
        {
            if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
            {
                j++;
            }
        }
        if (j < choice2)
        {
            return -1;
        }

        if (DEBUG)
            printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);

        //increase supply count for choosen card by amount being discarded
        state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;

        //each other player gains a copy of revealed card
        for (i = 0; i < state->numPlayers; i++)
        {
            if (i == currentPlayer)
            {
                gainCard(state->hand[currentPlayer][choice1], state, 0, i);
            }
        }

        //discard played card from hand
        discardCard(handPos, currentPlayer, state, 0);

        //trash copies of cards returned to supply
        for (j = 0; j < choice2; j++)
        {
            for (i = 0; i < state->handCount[currentPlayer]; i++)
            {
                if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
                {
                    discardCard(i, currentPlayer, state, 1);
                    break;
                }
            }
        }
	return 0;
}
