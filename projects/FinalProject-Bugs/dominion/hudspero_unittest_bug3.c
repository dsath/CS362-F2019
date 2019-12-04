//UNIT TEST FOR BUG 3 - Remodel If Statement
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
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	
	//INITIALIZE GAME 1
	struct gameState G;
	int players = rand()%3 + 2;
	memset(&G, 23, sizeof(struct gameState)); //SET GAME STATE
	int r = initializeGame(players, k, 12, &G); //BEGIN NEW GAME WITH 2-5 PLAYERS
	if (r != 0) {
		printf("\tERROR: Could not initialize game. Returned error code %d\n", r);
		return r;
	}
	
	printf("Testing Bug 3: Remodel If-Statement\n");
	
	//SET UP PLAYER'S HAND
	G.whoseTurn = 0;
	G.handCount[0] = 5;
	G.hand[0][0] = 12; //12 = remodel
	G.hand[0][1] = 1;  // 1 = estate  (cost 2)  
	G.hand[0][2] = 14; //14 = village (cost 3)
	G.hand[0][3] = 13; //13 = smithy  (cost 4) 
	G.hand[0][4] = 4;  // 4 = copper  (cost 0)
	
	//CASE 1: TRASHING AN ESTATE FOR AN ESTATE
	r = cardEffect(12, 1, 1, 0, &G, 0, 0);
	if (r != 0)
		printf("\tERROR: Could not swap estate for estate. Returned error code %d\n", r);
	else
		printf("\tSuccessfully swapped estate for estate\n");
	
	//CASE 2: TRASHING AN ESTATE FOR A VILLAGE
	r = cardEffect(12, 1, 14, 0, &G, 0, 0);
	if (r != 0)
		printf("\tERROR: Could not swap estate for village. Returned error code %d\n", r);
	else
		printf("\tSuccessfully swapped estate for village\n");
	
	//CASE 3: TRASHING AN ESTATE FOR A SMITHY
	r = cardEffect(12, 1, 13, 0, &G, 0, 0);
	if (r != 0)
		printf("\tERROR: Could not swap estate for smithy. Returned error code %d\n", r);
	else
		printf("\tSuccessfully swapped estate for smithy\n");
	
	//CASE 4: TRASHING AN ESTATE FOR A COPPER
	r = cardEffect(12, 1, 4, 0, &G, 0, 0);
	if (r != 0)
		printf("\tERROR: Could not swap estate for estate. Returned error code %d\n", r);
	else
		printf("\tSuccessfully swapped estate for copper\n");
	
	return 0;
}