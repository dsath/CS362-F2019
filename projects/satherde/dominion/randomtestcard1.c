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

int baron_func_test(struct gameState *state, int currentPlayer, int choice1); 
struct gameState* randomGameState();





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

		initializeGame(rand() % 5, k, rand(), &G);
		for( j = 0; j < 1000; j++) {
			baron_func_test(&G, rand() % 5, rand() % 3);
		}
	}

	return 0;
}

/*
struct gameState* randomGameState() {
	int i = 0;
	struct gameState *t = malloc(sizeof(struct gameState));
	t->numPlayers = rand() % 4;
	for( i = 0; i < treasure_map + 1; i ++) {
		t->supplyCount[i] = rand() % 15;
	}
	for( i = 0; i < treasure_map + 1; i ++) {
		t->embargoTokens[i] = rand() % 15;
	}
	t->outpostPlayed = rand() % 4;
	t->outpostTurn = rand() % 4;
	t->whoseTurn = rand() % 4;
	t->phase = rand() % 4;
	t->numActions = rand() % 4;
	t->coins = rand() % 4;
	t->numBuys = rand() % 4;

}
*/

int baron_func_test(struct gameState *state, int currentPlayer, int choice1) {
	state->numBuys++;//Increase buys by 1!
	if (choice1 > 0) { //Boolean true or going to discard an estate
	    //int p = 2;//Iterator for hand!
	    int p = 0;//Iterator for hand!
	    int card_not_discarded = 1;//Flag for discard set!
	    while(card_not_discarded) {
		if (state->hand[currentPlayer][p] == estate) { //Found an estate card!
		    state->coins += 4;//Add 4 coins to the amount of coins
		    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
		    state->discardCount[currentPlayer]++;
		    for (; p < state->handCount[currentPlayer]; p++) {
			state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
		    }
		    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
		    state->handCount[currentPlayer]--;
		    //card_not_discarded = 1;//Exit the loop
		    card_not_discarded = 0;//Exit the loop
		}
		else if (p > state->handCount[currentPlayer]) {
		    if(DEBUG) {
			printf("No estate cards in your hand, invalid choice\n");
			printf("Must gain an estate if there are any\n");
		    }
		    if (supplyCount(estate, state) > 0) {
			gainCard(estate, state, 0, currentPlayer);

			state->supplyCount[estate]--;//Decrement estates
			if (supplyCount(estate, state) == 0) {
			    isGameOver(state);
			}
		    }
		    card_not_discarded = 0;//Exit the loop
		}

		else {
		    p++;//Next card
		}
	    }
	}

	else {
	    if (supplyCount(estate, state) > 0) {
		gainCard(estate, state, 0, currentPlayer);//Gain an estate

		state->supplyCount[estate]--;//Decrement Estates
		if (supplyCount(estate, state) == 0) {
		    isGameOver(state);
		}
	    }
	}
	return 0;
}

