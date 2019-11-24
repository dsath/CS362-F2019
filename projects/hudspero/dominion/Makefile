CFLAGS= -Wall -ftest-coverage -fprofile-arcs -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/

#testDrawCard: testDrawCard.c dominion.o rngs.o
#	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc  -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc  -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc  -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc  -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	
unittest5: unittest5.c dominion.o rngs.o
	gcc  -o unittest5 unittest5.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: unittest1 unittest2 unittest3 unittest4 unittest5
	./unittest1 &> unittest1result.out
	gcov dominion.c -b -f >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out
	./unittest2 &> unittest2result.out
	gcov dominion.c -b -f >> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out
	./unittest3 &> unittest3result.out
	gcov dominion.c -b -f >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out
	./unittest4 &> unittest4result.out
	gcov dominion.c -b -f >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out
	./unittest5 &> unittest5result.out
	gcov dominion.c -b -f >> unittest5result.out
	cat dominion.c.gcov >> unittest5result.out

player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe 
	rm -f unittest1 unittest2 unittest3 unittest4 unittest5