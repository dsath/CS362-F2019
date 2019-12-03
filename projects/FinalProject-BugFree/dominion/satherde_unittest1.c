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
	G.handCount[0] = 4;
	G.discardCount[0] = 6;
	firstScore = scoreFor(0, &G);

	G.handCount[0] = 4;
	G.discardCount[0] = 2;
	secondScore = scoreFor(0, &G);
	
	if( ! (firstScore == secondScore) ) {
		printf("%s\n", "Assert Failed: (firstScore == secondScore)");
		fprintf(stderr, "%s\n",  "Assert Failed: (firstScore == secondScore)");
	}
	return 0;
}

