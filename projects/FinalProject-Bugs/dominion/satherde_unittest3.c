///////////////////////////////////////////
// Baron Unit Tests
//////////////////////////////////////////


//int baron_func(struct gameState *state, int currentPlayer, int choice1);

#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


	
int main() {
	int i;
	int top;
	int firstScore;
	int secondScore;
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
	G.whoseTurn = 0;
	G.handCount[0] = 5;
	G.coins = 0;
	G.numActions = 1;
	G.phase = 0;

	for(i = 0; i < 5; i++) {
		G.hand[0][i] = tribute;
	}


//set top five cards in next player's deck to treasures
	top = G.deckCount[1] - 1;
		G.deck[1][top] = copper;
		G.deck[1][top - 1] = silver;
		G.deck[1][top - 2] = gold;

		G.deck[1][0] = copper;
		G.deck[1][1] = silver;
		G.deck[1][2] = gold;



	if(playCard(3, 0, 0, 0, &G) == -1) {
		fprintf(stderr, "%s\n", "Playcard failed\n");
	}
	
	if( ! (G.coins == 3) ) {
		printf("%s\n", "Assert Failed: (i < 2)");
		fprintf(stderr, "%s\n",  "Assert Failed: (i < 2)");
	}
	return 0;
}

