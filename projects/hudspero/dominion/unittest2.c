//UNIT TEST FOR playBaron FUNCTION, REFACTORED
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//MAX_DECK = 500, defined in dominion.h
//MAX_HAND = 500, defined in dominion.h

struct gameState G;

int main () {

	//INITIALIZE NECESSARY INDEXES AND GAME VARIABLES
	int n, i;
	struct gameState G;

	printf("unittest2.c, Testing playBaron():\n");

	//SEEDING FOR RANDOM NUMBER GENERATION
	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) { //RUN 2000 TIMES
		for (i = 0; i < sizeof(struct gameState); i++) { //GENERATE A RANDOM GAME STATE
			((char*)&G)[i] = floor(Random() * 256);}
		
		printf("Beginning testBaron1.\n");
		G.deckCount[0] = 0; //EMPTY DECK FOR EASE OF TESTING
		G.discardCount[0] = 0;//EMPTY DISCARD PILE FOR EASE OF TESTING
		G.handCount[0] = 5; //PLAYER HOLDS ONLY 5 CARDS
		G.whoseTurn = 0; //SET PLAYER 1
		G.coins = 0; //PLAYER HAS NO COINS
		G.numBuys = 1; //PLAYER HAS ONE BUY
		
		//STORE PRE-FUNCTION DATA FOR COMPARISON AFTER RUNNING
		int preDeckCount = G.deckCount[0];
		int preDiscardCount = G.discardCount[0];
		int preHandCount = G.handCount[0];
		int preCoins = G.coins;
		int preBuys = G.numBuys;
		
		//DEFINE PLAYER'S HAND
		G.hand[0][0] = baron;
		G.hand[0][1] = copper;
		G.hand[0][2] = copper; 
		G.hand[0][3] = copper; 
		G.hand[0][4] = copper;
		printf("\t testBaron1: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playBaron(0, &G, 0); //NO ESTATES IN HAND
		
		//OUTPUT ANY CHANGES MADE AFTER RUNNING THE FUNCTION
		if(preDeckCount != G.deckCount[0])
			printf("\t testBaron1: deckCount changed from %d to %d\n", preDeckCount, (int)G.deckCount[0]);
	
		if(preDiscardCount != G.discardCount[0])
			printf("\t testBaron1: discardCount changed from %d to %d\n", preDiscardCount, (int)G.discardCount[0]);
		
		if(preHandCount != G.handCount[0])
			printf("\t testBaron1: handCount changed from %d to %d\n", preHandCount, (int)G.handCount[0]);
		
		if(preCoins != G.coins)
			printf("\t testBaron1: coin amount changed from %d to %d\n", preCoins, (int)G.coins);
		
		if(preBuys != G.numBuys)
			printf("\t testBaron1: buy amount changed from %d to %d\n", preBuys, (int)G.numBuys);
	
		printf("\t testBaron1: Player's hand AFTER: %d, %d, %d, %d, %d\n\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		
		
		printf("Beginning testBaron2.\n");
		G.deckCount[0] = 0; //EMPTY DECK FOR EASE OF TESTING
		G.discardCount[0] = 0;//EMPTY DISCARD PILE FOR EASE OF TESTING
		G.handCount[0] = 5; //PLAYER HOLDS ONLY 5 CARDS
		G.whoseTurn = 0; //SET PLAYER 1
		G.coins = 0; //PLAYER HAS NO COINS
		G.numBuys = 1; //PLAYER HAS ONE BUY
		
		//STORE PRE-FUNCTION DATA FOR COMPARISON AFTER RUNNING
		preDeckCount = G.deckCount[0];
		preDiscardCount = G.discardCount[0];
		preHandCount = G.handCount[0];
		preCoins = G.coins;
		
		//DEFINE PLAYER'S HAND
		G.hand[0][0] = baron;
		G.hand[0][1] = copper;
		G.hand[0][2] = estate; 
		G.hand[0][3] = copper; 
		G.hand[0][4] = copper;
		printf("\t testBaron2: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playBaron(1, &G, 0); //NO ESTATES IN HAND
		
		//OUTPUT ANY CHANGES MADE AFTER RUNNING THE FUNCTION
		if(preDeckCount != G.deckCount[0])
			printf("\t testBaron2: deckCount changed from %d to %d\n", preDeckCount, (int)G.deckCount[0]);
	
		if(preDiscardCount != G.discardCount[0])
			printf("\t testBaron2: discardCount changed from %d to %d\n", preDiscardCount, (int)G.discardCount[0]);
		
		if(preHandCount != G.handCount[0])
			printf("\t testBaron1: handCount changed from %d to %d\n", preHandCount,(int)G.handCount[0]);
		
		if(preCoins != G.coins)
			printf("\t testBaron1: coin amount changed from %d to %d\n", preCoins, (int)G.coins);
		
		if(preBuys != G.numBuys)
			printf("\t testBaron1: buy amount changed from %d to %d\n", preBuys, (int)G.numBuys);
	
		printf("\t testBaron2: Player's hand AFTER: %d, %d, %d, %d, %d\n\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		
		
		printf("Beginning testBaron3.\n");
		G.deckCount[0] = 0; //EMPTY DECK FOR EASE OF TESTING
		G.discardCount[0] = 0;//EMPTY DISCARD PILE FOR EASE OF TESTING
		G.handCount[0] = 5; //PLAYER HOLDS ONLY 5 CARDS
		G.whoseTurn = 0; //SET PLAYER 1
		G.coins = 0; //PLAYER HAS NO COINS
		G.numBuys = 1; //PLAYER HAS ONE BUY
		
		//STORE PRE-FUNCTION DATA FOR COMPARISON AFTER RUNNING
		preDeckCount = G.deckCount[0];
		preDiscardCount = G.discardCount[0];
		preHandCount = G.handCount[0];
		preCoins = G.coins;
		
		//DEFINE PLAYER'S HAND
		G.hand[0][0] = baron;
		G.hand[0][1] = estate;
		G.hand[0][2] = estate; 
		G.hand[0][3] = estate; 
		G.hand[0][4] = copper;
		printf("\t testBaron3: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playBaron(1, &G, 0); //NO ESTATES IN HAND
		
		//OUTPUT ANY CHANGES MADE AFTER RUNNING THE FUNCTION
		if(preDeckCount != G.deckCount[0])
			printf("\t testBaron2: deckCount changed from %d to %d\n", preDeckCount, (int)G.deckCount[0]);
	
		if(preDiscardCount != G.discardCount[0])
			printf("\t testBaron2: discardCount changed from %d to %d\n", preDiscardCount, (int)G.discardCount[0]);
		
		if(preHandCount != G.handCount[0])
			printf("\t testBaron1: handCount changed from %d to %d\n", preHandCount,(int)G.handCount[0]);
		
		if(preCoins != G.coins)
			printf("\t testBaron1: coin amount changed from %d to %d\n", preCoins, (int)G.coins);
	
		printf("\t testBaron3: Player's hand AFTER: %d, %d, %d, %d, %d\n\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
	}

   return 0;
}