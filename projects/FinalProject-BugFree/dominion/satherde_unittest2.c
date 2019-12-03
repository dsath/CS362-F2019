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
	G.coins = 3;
	G.numActions = 1;
	G.phase = 0;
	for(i = 0; i < 5; i++) {
		G.hand[0][i] = feast;
	}
	fprintf(stderr, "The card is: %d\n", G.hand[0][3]);
	if(playCard(3, 0, 0, 0, &G) == -1) {
		fprintf(stderr, "%s\n", "Playcard failed\n");
	}
	
	if( ! (G.coins == 3) ) {
		printf("%s\n", "Assert Failed: (G.coins == 3)");
		fprintf(stderr, "%s\n",  "Assert Failed: (G.coins == 3)");
	}
	return 0;
}

