//UNIT TEST FOR playMinion FUNCTION, REFACTORED
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
	int flag = 0;
	srand(time(NULL));

	//SEEDING FOR RANDOM NUMBER GENERATION
	SelectStream(2);
	PutSeed(3);
	
	printf("unittest3.c, Testing playMinion():\n");

	for (n = 0; n < 2000; n++) { //RUN 2000 TIMES
		struct gameState G;
		memset(&G, 23, sizeof(struct gameState)); //SET GAME STATE
		int r = initializeGame(2, k, 12, &G); //BEGIN NEW GAME WITH TWO PLAYERS
		if (r != 0) {
			printf("ERROR: Could not initialize game. Returned error code %d\n", r);
			return r;
		}
		
		printf("\tBeginning testMinion.\n");
		
		G.deckCount[0] = 0; //EMPTY DECK FOR EASE OF TESTING
		G.discardCount[0] = 0;//EMPTY DISCARD PILE FOR EASE OF TESTING
		G.whoseTurn = 0; //SET PLAYER 1
		G.coins = 0; //PLAYER HAS NO COINS
		
		//STORE PRE-FUNCTION DATA FOR COMPARISON AFTER RUNNING
		int preDeckCount1 = G.deckCount[0];
		int preDiscardCount1 = G.discardCount[0];
		int preHandCount1 = G.handCount[0];
		int preDeckCount2 = G.deckCount[1];
		int preDiscardCount2 = G.discardCount[1];
		int preHandCount2 = G.handCount[1];
		int preCoins = G.coins;
		
		//DEFINE PLAYER'S HAND
		G.hand[0][0] = minion;
		G.hand[0][1] = rand() % 26;
		G.hand[0][2] = rand() % 26;
		G.hand[0][3] = rand() % 26;
		G.hand[0][4] = rand() % 26;
		printf("\t testMinion: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playMinion(flag, !flag, &G, 0);
		
		//OUTPUT ANY CHANGES MADE AFTER RUNNING THE FUNCTION
		if(preDeckCount1 != G.deckCount[0])
			printf("\t testMinion: deckCount1 changed from %d to %d\n", preDeckCount1, (int)G.deckCount[0]);
	
		if(preDiscardCount1 != G.discardCount[0])
			printf("\t testMinion: discardCount1 changed from %d to %d\n", preDiscardCount1, (int)G.discardCount[0]);
		
		if(preHandCount1 != G.handCount[0])
			printf("\t testMinion: handCount1 changed from %d to %d\n", preHandCount1, (int)G.handCount[0]);
		
		if(preDeckCount2 != G.deckCount[1])
			printf("\t testMinion: deckCount2 changed from %d to %d\n", preDeckCount2, (int)G.deckCount[1]);
	
		if(preDiscardCount2 != G.discardCount[1])
			printf("\t testMinion: discardCount2 changed from %d to %d\n", preDiscardCount2, (int)G.discardCount[1]);
		
		if(preHandCount2 != G.handCount[1])
			printf("\t testMinion: handCount2 changed from %d to %d\n", preHandCount2, (int)G.handCount[1]);
		
		if(preCoins != G.coins)
			printf("\t testMinion: coin amount changed from %d to %d\n", preCoins, (int)G.coins);
	
		printf("\t testMinion: Player's hand AFTER: %d, %d, %d, %d, %d\n\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		
		flag = !flag;
	}
	
	return 0;
}