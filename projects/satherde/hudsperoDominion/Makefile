CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

alltests: 
	gcc -g -o randomtestcard1 randomtestcard1.c dominion.c rngs.c -lm -coverage
	gcc -g -o randomtestcard2 randomtestcard2.c dominion.c rngs.c -lm -coverage
	gcc -g -o randomtestcard3 randomtestcard3.c dominion.c rngs.c -lm -coverage
	randomtestcard1
	randomtestcard2
	randomtestcard3
	gcov randomtestcard1.c -b -f >> randomtestresults.out
	gcov randomtestcard2.c -b -f >> randomtestresults.out
	gcov randomtestcard3.c -b -f >> randomtestresults.out
	

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
