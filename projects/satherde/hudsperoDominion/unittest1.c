/** UNIT TEST FOR playMine FUNCTION, REFACTORED **/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//MAX_DECK = 500, defined in dominion.h
//MAX_HAND = 500, defined in dominion.h

void testMine(int loop_number, int card1, int card2, struct gameState* game, int handPos) {
	int oracle; //STORE EXIT RESULT FROM FUNCTION
	oracle = playMine(card1, card2, game, handPos);
	if(oracle != 0)
		printf("\tLoop %d: Could not discard %d for %d\n", loop_number, card1, card2);
	}

int main () {

	//INITIALIZE NECESSARY INDEXES AND GAME VARIABLES
	int n, i, j, l;
	struct gameState G;

	printf("unittest1.c, Testing playMine():\n");

	//SEEDING FOR RANDOM NUMBER GENERATION
	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) { //RUN 2000 TIMES
		for (i = 0; i < sizeof(struct gameState); i++) { //GENERATE A RANDOM GAME STATE
			((char*)&G)[i] = floor(Random() * 256);}

		G.deckCount[0] = floor(Random() * MAX_DECK);    //DEFINES RANDOM NUMBER OF CARDS IN DECK
		G.discardCount[0] = floor(Random() * MAX_DECK); //DEFINES RANDOM NUMBER OF CARDS IN DISCARD PILE
		G.handCount[0] = 5; //PLAYER HOLDS ONLY 5 CARDS
		G.whoseTurn = 0; //SET PLAYER 1

		//TEST playMine() function
		for(j = 1; j < 4; j++) {
			for(l = 1; l < 4; l++) {
				//ASSIGN THE PLAYER A SPECIFIC HAND; BUG APPEARS ONLY IN SPECIFIC CONDITION WHEN PLAYING MINE CARD
				G.hand[0][0] = mine;
				G.hand[0][1] = copper; //enum value 4
				G.hand[0][2] = silver; //enum value 5
				G.hand[0][3] = gold;   //enum value 6
				G.hand[0][4] = estate;
				printf("\t\tBEFORE: Player's hand: %d, %d, %d, %d, %d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
				testMine(n, G.hand[0][j], G.hand[0][l], &G, 0); //RUN THE TEST
				
				printf("\t\tAFTER (l-loop): Player's hand: %d, %d, %d, %d, %d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
			}
			printf("\tAFTER (j-loop): Player's hand: %d, %d, %d, %d, %d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);	
		}
		printf("AFTER (n-loop): Player's hand: %d, %d, %d, %d, %d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
	}

	return 0;
}