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


//int tribute_func_test(struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards); 
int playTribute_test(struct gameState *state, int handPos); 

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
			if(rand() % 100 == 2) {
				G.deckCount[1] = 0;
			}
			int tributeRevealedCards[2] = {-1, -1};
			//tribute_func_test(&G, 0, 1, tributeRevealedCards);
			playTribute_test(&G, 2);
		}
	}

	return 0;
}
/*
int tribute_func_test(struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards) {
	int i = 0;
        if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1) {
            if (state->deckCount[nextPlayer] > 0) {
                tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
                state->deckCount[nextPlayer]--;
            }
            else if (state->discardCount[nextPlayer] > 0) {
                tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
                state->discardCount[nextPlayer]--;
            }
            else {
                //No Card to Reveal
                if (DEBUG) {
                    printf("No cards to reveal\n");
                }
            }
        }

        else {
            if (state->deckCount[nextPlayer] == 0) {
                for (i = 0; i < state->discardCount[nextPlayer]; i++) {
                    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
                    state->deckCount[nextPlayer]++;
                    state->discard[nextPlayer][i] = -1;
                    state->discardCount[nextPlayer]--;
                }

                shuffle(currentPlayer, state);//Shuffle the deck
            }
            tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
            state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
            state->deckCount[nextPlayer]--;
            tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
            state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
            state->deckCount[nextPlayer]--;
        }

        if (tributeRevealedCards[0] == tributeRevealedCards[1]) { //If we have a duplicate card, just drop one
            state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
            state->playedCardCount++;
            tributeRevealedCards[1] = -1;
        }

        for (i = 0; i <= 2; i ++) {
            if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold) { //Treasure cards
                state->coins -= 2;
            }

            else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall) { //Victory Card Found
                drawCard(currentPlayer, state);
                drawCard(currentPlayer, state);
            }
            else { //Action Card
                state->numActions = state->numActions + 2;
            }
        }

        return 0;
}
*/

int playTribute_test(struct gameState *state, int handPos) {
	int currentPlayer = 0;
    int nextPlayer = currentPlayer + 1;
	int tributeRevealedCards[2] = {-1, -1};
	int i;
	
	if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1) {
		if (state->deckCount[nextPlayer] > 0) {
			tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
			state->deckCount[nextPlayer]--;
		}
		else if (state->discardCount[nextPlayer] > 0) {
			tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
			state->discardCount[nextPlayer]--;
		}
		else {
			//No Card to Reveal
			if (DEBUG) {
				printf("No cards to reveal\n");
			}
		}
	}

	else {
		if (state->deckCount[nextPlayer] == 0) {
			for (i = 0; i < state->discardCount[nextPlayer]; i++) {
				state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
				state->deckCount[nextPlayer]++;
				state->discard[nextPlayer][i] = -1;
				state->discardCount[nextPlayer]--;
			}

			shuffle(nextPlayer,state);//Shuffle the deck
		}
		tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
		state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
		state->deckCount[nextPlayer]--;
		tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
		state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
		state->deckCount[nextPlayer]--;
	}

	if (tributeRevealedCards[0] == tributeRevealedCards[1]) { //If we have a duplicate card, just drop one
		state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
		state->playedCardCount++;
		tributeRevealedCards[1] = -1;
	}

	for (i = 0; i <= 2; i ++) {
		if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold) { //Treasure cards
			state->coins += 3; //BUG! Should be 2, not 3
		}

		else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall) { //Victory Card Found
			drawCard(currentPlayer, state);
			drawCard(currentPlayer, state);
		}
		else { //Action Card
			state->numActions = state->numActions + 1; //BUG! Should add 2 Actions, not just 1
		}
	}

	return 0;
}
