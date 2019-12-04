//UNIT TEST FOR BUG 1 - Mine Discard
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
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	
	//INITIALIZE GAME
	struct gameState G;
	int players = rand()%3 + 2;
	memset(&G, 23, sizeof(struct gameState)); //SET GAME STATE
	int r = initializeGame(players, k, 12, &G); //BEGIN NEW GAME WITH 2-5 PLAYERS
	if (r != 0) {
		printf("ERROR: Could not initialize game. Returned error code %d\n", r);
		return r;
	}
	
	printf("Testing Bug 1: Mine Discard\n");
	
	//SET UP PLAYER'S HAND
	G.whoseTurn = 0;
	G.handCount[0] = 5;
	G.hand[0][0] = 11; //11 = mine
	G.hand[0][1] = 4;  //4 = copper
	G.hand[0][2] = 1;  //1 = estate
	G.hand[0][3] = 4;  //4 = copper
	G.hand[0][4] = 1;  //1 = estate
	
	//STORE AMOUNT OF COPPERS IN PLAYER'S DECK BEFORE PLAYING CARD (NO CARDS HAVE BEEN DISCARDED)
	int allDeck = G.deckCount[0];
	int allHand = G.handCount[0];
	int allPlayed = G.playedCardCount;
	int preCoppers = 0;
	
	for (i = 0; i < allDeck; i++) {
		if (G.deck[0][i] == 4) {
			printf("\tFound copper at G.deck[0][%d]\n", i);
			preCoppers++;
		}
	}
	for (i = 0; i < allHand; i++) {
		if (G.hand[0][i] == 4) {
			printf("\tFound copper at G.hand[0][%d]\n", i);
			preCoppers++;
		}
	}
	for (i = 0; i < allPlayed; i++) {
		if (G.playedCards[i] == 4) {
			printf("\tFound copper at G.playedCards[%d]\n", i);
			preCoppers++;
		}
	}	
	printf("Players STARTS with %d coppers\n", preCoppers);
	
	//PLAY THE MINE CARD
	r = cardEffect(mine, 1, silver, 0, &G, 0, 0);
	if (r != 0) {
		printf("ERROR: Could not play card. Returned error code %d\n", r);
		return r;
	}
	
	//STORE AMOUNT OF COPPERS IN PLAYER'S DECK AFTER PLAYING CARD
	allDeck = G.deckCount[0];
	allHand = G.handCount[0];
	allPlayed = G.playedCardCount;
	int postCoppers = 0;
	
	for (i = 0; i < allDeck; i++) {
		if (G.deck[0][i] == 4) {
			printf("\tFound copper at G.deck[0][%d]\n", i);
			postCoppers++;
		}
	}
	for (i = 0; i < allHand; i++) {
		if (G.hand[0][i] == 4) {
			printf("\tFound copper at G.hand[0][%d]\n", i);
			postCoppers++;
		}
	}
	for (i = 0; i < allPlayed; i++) {
		if (G.playedCards[i] == 4) {
			printf("\tFound copper at G.playedCards[%d]\n", i);
			postCoppers++;
		}
	}
	printf("Players ENDS with %d coppers\n", postCoppers);
	
	if(preCoppers == postCoppers)
		printf("(preCoppers == postCoppers) -> (%d == %d). The function does not discard appropriately.\n\n", preCoppers, postCoppers);
	
	return 0;
}