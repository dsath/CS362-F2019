//UNIT TEST FOR playTribute FUNCTION, REFACTORED
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	
	//INITIALIZE NECESSARY INDEXES AND GAME VARIABLES
	int n;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));

	//SEEDING FOR RANDOM NUMBER GENERATION
	SelectStream(2);
	PutSeed(3);
	
	printf("unittest4.c, Testing playTribute():\n");
	
	for (n = 0; n < 2000; n++) { //RUN 2000 TIMES
		struct gameState G;
		memset(&G, 23, sizeof(struct gameState)); //SET GAME STATE
		int r = initializeGame(rand()%3 + 2, k, 12, &G); //BEGIN NEW GAME WITH 2-5 PLAYERS
		if (r != 0) {
			printf("ERROR: Could not initialize game. Returned error code %d\n", r);
			return r;
		}
		
		printf("\tBeginning testTribute.\n");
		
		//SAVING PRE-GAME VARIABLES TO EXPOSE THE BUGS I IMPLEMENTED
		int preActions = G.numActions;
		int preCoins = G.coins;
		int preDiscardCount = G.discardCount[0];
		int preHandCount = G.handCount[0];
		
		//SETTING GAME TURN & HAND
		G.whoseTurn = 0;
		G.hand[0][0] = tribute;
		G.hand[0][1] = rand() % 26;
		G.hand[0][2] = rand() % 26;
		G.hand[0][3] = rand() % 26;
		G.hand[0][4] = rand() % 26;
		
		//RUNNING THE FUNCTION
		printf("\ttestTribute: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playTribute(&G, 0);
		
		//COMPARING WHAT CHANGED AFTER THE FUNCTION WAS RUN
		if(preActions != G.numActions)
			printf("\t testTribute: numActions changed from %d to %d\n", preActions, (int)G.numActions);
		
		if(preCoins != G.coins)
			printf("\t testTribute: coins changed from %d to %d\n", preCoins, (int)G.coins);
		
		if(preDiscardCount != G.discardCount[0])
			printf("\t testMinion: discardCount changed from %d to %d\n", preDiscardCount, (int)G.discardCount[0]);
		
		if(preHandCount != G.handCount[0])
			printf("\t testMinion: handCount changed from %d to %d\n", preHandCount, (int)G.handCount[0]);
		
		printf("\ttestTribute: Player's hand AFTER: %d, %d, %d, %d, %d\n\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		
	}	

	return 0;
}