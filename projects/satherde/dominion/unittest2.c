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


int minion_func_test(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2); 
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
	minion_func_test(&G, 0, 0, 0, 1);
	minion_func_test(&G, 0, 0, 1, 0);

	return 0;
}

int minion_func_test(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2) {
	int i = 0;
	int j = 0;

        //+1 action
        state->numActions++;

        //discard card from hand
        discardCard(handPos, currentPlayer, state, 0);

		if (choice1)
        {
            state->coins = state->coins + 4;
        }
        else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
        {
            //discard hand
            while(numHandCards(state) > 0)
            {
                discardCard(handPos, currentPlayer, state, 0);
            }

            //draw 4
            for (i = 0; i < 2; i++)
            {
                drawCard(currentPlayer, state);
            }

            //other players discard hand and redraw if hand size > 4
            for (i = 0; i < state->numPlayers; i++)
            {
                if (i != currentPlayer)
                {
                    if ( state->handCount[i] > 4 )
                    {
                        //discard hand
                        while( state->handCount[i] > 0 )
                        {
                            discardCard(handPos, i, state, 0);
                        }

                        //draw 4
                        for (j = 0; j < 4; j++)
                        {
                            drawCard(i, state);
                        }
                    }
                }
            }

        }
	return 0;
}

