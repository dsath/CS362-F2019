//UNIT TEST FOR playAmbassador FUNCTION, REFACTORED
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
	int n, i;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));

	//SEEDING FOR RANDOM NUMBER GENERATION
	SelectStream(2);
	PutSeed(3);
	
	printf("unittest5.c, Testing playAmbassador():\n");
	
	for (n = 0; n < 2000; n++) { //RUN 2000 TIMES
		struct gameState G;
		int players = rand()%3 + 2;
		memset(&G, 23, sizeof(struct gameState)); //SET GAME STATE
		int r = initializeGame(players, k, 12, &G); //BEGIN NEW GAME WITH 2-5 PLAYERS
		if (r != 0) {
			printf("ERROR: Could not initialize game. Returned error code %d\n", r);
			return r;
		}
		
		printf("\tBeginning testAmbassador.\n");
		
		//SAVING SUPPLY COUNTERS FOR ALL KINGDOM CARDS
		int preAdventurer = G.supplyCount[adventurer];
		int preCouncilRoom = G.supplyCount[council_room];
		int preFeast = G.supplyCount[feast];
		int preGardens = G.supplyCount[gardens];
		int preMine = G.supplyCount[mine];
		int preRemodel = G.supplyCount[remodel];
		int preSmithy = G.supplyCount[smithy];
		int preVillage = G.supplyCount[village];
		int preBaron = G.supplyCount[baron];
		int preGreatHall = G.supplyCount[great_hall];
		
		//SAVING DISCARD AND HAND COUNT VARIABLES TO DEMONSTRATE BUGS
		int preDiscardCount = G.discardCount[0];

		//SETTING GAME TURN & HAND
		G.whoseTurn = 0;
		G.hand[0][0] = ambassador;
		G.hand[0][1] = rand() % 9 + 7;
		G.hand[0][2] = rand() % 9 + 7;
		G.hand[0][3] = rand() % 9 + 7;
		G.hand[0][4] = rand() % 9 + 7;
		
		//RUNNING THE FUNCTION
		printf("\ttestTribute: Player's hand BEFORE: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
		playAmbassador(rand()%3 + 1, 2, &G, 0);
		
		if(preAdventurer != G.supplyCount[adventurer])
			printf("\t testAmbassador: Adventurer supply count changed from %d to %d\n", preAdventurer, (int)G.supplyCount[adventurer]);
		
		if(preCouncilRoom != G.supplyCount[council_room])
			printf("\t testAmbassador: Council Room supply count changed from %d to %d\n", preCouncilRoom, (int)G.supplyCount[council_room]);
		
		if(preFeast != G.supplyCount[feast])
			printf("\t testAmbassador: Feast supply count changed from %d to %d\n", preFeast, (int)G.supplyCount[feast]);
		
		if(preGardens != G.supplyCount[gardens])
			printf("\t testAmbassador: Gardens supply count changed from %d to %d\n", preGardens, (int)G.supplyCount[gardens]);
		
		if(preMine != G.supplyCount[mine])
			printf("\t testAmbassador: Mine supply count changed from %d to %d\n", preMine, (int)G.supplyCount[mine]);
		
		if(preRemodel != G.supplyCount[remodel])
			printf("\t testAmbassador: Remodel supply count changed from %d to %d\n", preRemodel, (int)G.supplyCount[remodel]);
		
		if(preSmithy != G.supplyCount[smithy])
			printf("\t testAmbassador: Smithy supply count changed from %d to %d\n", preSmithy, (int)G.supplyCount[smithy]);
		
		if(preVillage != G.supplyCount[village])
			printf("\t testAmbassador: Village supply count changed from %d to %d\n", preVillage, (int)G.supplyCount[village]);
		
		if(preBaron != G.supplyCount[baron])
			printf("\t testAmbassador: Baron supply count changed from %d to %d\n", preBaron, (int)G.supplyCount[baron]);
		
		if(preGreatHall != G.supplyCount[great_hall])
			printf("\t testAmbassador: Great Hall supply count changed from %d to %d\n", preGreatHall, (int)G.supplyCount[great_hall]);
		
		for(i = 0; i < players; i++) {
			if(preDiscardCount != G.discardCount[i])
				printf("\t testAmbassador: discardCount for player %d changed from %d to %d\n", i, preDiscardCount, (int)G.supplyCount[great_hall]);
		}
		
		printf("\ttestTribute: Player's hand AFTER: %d, %d, %d, %d, %d\n", (int)G.hand[0][0], (int)G.hand[0][1], (int)G.hand[0][2], (int)G.hand[0][3], (int)G.hand[0][4]);
	}
	
	return 0;
}