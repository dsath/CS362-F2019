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


int tribute_func_test(struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards); 
int main() {
	int *x = 0;
    int tributeRevealedCards[2] = {-1, -1};
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
	tribute_func_test(&G, 0, 0, tributeRevealedCards) ;
	tribute_func_test(&G, 0, 0, tributeRevealedCards);
	tribute_func_test(&G, 0, 0, tributeRevealedCards);

	return 0;
}

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
