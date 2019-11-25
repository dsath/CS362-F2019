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


//int minion_func_test(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2); 
int playMinion_test(int choice1, int choice2, struct gameState *state, int handPos); 


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
	
	int i = 0;
	int j = 0;
	for( i = 0; i < 1000; i++) {

		initializeGame(2, k, rand(), &G);
		for( j = 0; j < 1000; j++) {
			//minion_func_test(&G, 1, 2, rand() % 3, rand() % 3);
			playMinion_test(rand() % 3, rand() % 3, &G, 2);
		}
	}

	return 0;
}

/*
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

*/

int playMinion_test(int choice1, int choice2, struct gameState *state, int handPos) {
	int currentPlayer = 1;
	int i, j;
	state->numActions++; //+1 action
	discardCard(handPos, currentPlayer, state, 0); //discard card from hand

	if (choice1) {
		state->coins = state->coins + 1; //BUG! Should be +2
	}
	else if (choice2) { //discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
		while(numHandCards(state) > 0) { //discard hand
			discardCard(handPos, currentPlayer, state, 0); //BUG! trashFlag should be set to 0, not 1 (had to revert to run tests)
			//discardCard(handPos, currentPlayer, state, 1); //BUG! trashFlag should be set to 0, not 1 (had to revert to run tests)
		}

		for (i = 0; i < 4; i++) { //draw 4
			drawCard(currentPlayer, state);
		}

		//other players discard hand and redraw if hand size > 4
		for (i = 0; i < state->numPlayers; i++) {
			if (i != currentPlayer) {
				if ( state->handCount[i] > 4 ) {
					while( state->handCount[i] > 0 ) { //discard hand
						discardCard(handPos, i, state, 0);
					}

					for (j = 0; j < 4; j++) { //draw 4
						drawCard(i, state);
					}
				}
			}
		}

	}
	return 0;
}
