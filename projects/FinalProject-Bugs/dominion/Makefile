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

all: playdom player 

unittestresults: bug5 bug6 #bug7
	satherde_unittest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	satherde_unittest2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

bug5:
	gcc -o satherde_unittest1 satherde_unittest1.c dominion.c rngs.c -lm -coverage

bug6:
	gcc -o satherde_unittest2 satherde_unittest2.c dominion.c rngs.c -lm -coverage

bug7:
	gcc -o satherde_unittest3 satherde_unittest3.c dominion.c rngs.c -lm -coverage

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe satherde_unittest1 satherde_unittest2 satherde_unittest3
