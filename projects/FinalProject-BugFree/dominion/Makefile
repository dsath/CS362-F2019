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

bug2: eckertl_unittest1.c dominion.o rngs.o
	gcc  -o eckertl_unittest1 eckertl_unittest1.c -g dominion.o rngs.o $(CFLAGS)

bug8: eckertl_unittest2.c dominion.o rngs.o
	gcc  -o eckertl_unittest2 eckertl_unittest2.c -g dominion.o rngs.o $(CFLAGS)

bug9: eckertl_unittest3.c dominion.o rngs.o
	gcc  -o eckertl_unittest3 eckertl_unittest3.c -g dominion.o rngs.o $(CFLAGS)

bug10: eckertl_unittest4.c dominion.o rngs.o
	gcc  -o eckertl_unittest4 eckertl_unittest4.c -g dominion.o rngs.o $(CFLAGS)

bug5: satherde_unittest1.c dominion.o rngs.o
	gcc -o satherde_unittest1 satherde_unittest1.c -g dominion.c rngs.o $(CFLAGS)

bug6: satherde_unittest2.c dominion.o rngs.o
	gcc -o satherde_unittest2 satherde_unittest2.c -g dominion.c rngs.o $(CFLAGS)

bug7: satherde_unittest3.c dominion.o rngs.o
	gcc -o satherde_unittest3 satherde_unittest3.c -g dominion.c rngs.o $(CFLAGS)

bug1: hudspero_unittest_bug1.c dominion.o rngs.o
	gcc -o hudspero_unittest_bug1 hudspero_unittest_bug1.c -g dominion.c rngs.o $(CFLAGS)

bug3: hudspero_unittest_bug3.c dominion.o rngs.o
	gcc -o hudspero_unittest_bug3 hudspero_unittest_bug3.c -g dominion.c rngs.o $(CFLAGS)

bug4: hudspero_unittest_bug4.c dominion.o rngs.o
	gcc -o hudspero_unittest_bug4 hudspero_unittest_bug4.c -g dominion.c rngs.o $(CFLAGS)

eckertl: bug2 bug8 bug9 bug10
	./eckertl_unittest1 &> unittest1result.out
	gcov dominion.c -b -f >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out
	./eckertl_unittest2 &> unittest2result.out
	gcov dominion.c -b -f >> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out
	./eckertl_unittest3 &> unittest3result.out
	gcov dominion.c -b -f >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out
	./eckertl_unittest4 &> unittest4result.out
	gcov dominion.c -b -f >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out

satherde: bug5 bug6 bug7
	./satherde_unittest1 &> satherde_unittest5result.out
	gcov dominion.c -b -f >> satherde_unittest5result.out
	cat dominion.c.gcov >> satherde_unittest5result.out
	./satherde_unittest2 &> satherde_unittest6result.out
	gcov dominion.c -b -f >> satherde_unittest6result.out
	cat dominion.c.gcov >> satherde_unittest6result.out
	./satherde_unittest3 &> satherde_unittest7result.out
	gcov dominion.c -b -f >> satherde_unittest7result.out
	cat dominion.c.gcov >> satherde_unittest7result.out

hudspero: bug1 bug3 bug4
	./hudspero_unittest_bug1 &> hudspero_unittest1result.out
	gcov dominion.c -b -f >> hudspero_unittest1result.out
	cat dominion.c.gcov >> hudspero_unittest1result.out
	./hudspero_unittest_bug3 &> hudspero_unittest3result.out
	gcov dominion.c -b -f >> hudspero_unittest3result.out
	cat dominion.c.gcov >> hudspero_unittest3result.out
	./hudspero_unittest_bug4 &> hudspero_unittest4result.out
	gcov dominion.c -b -f >> hudspero_unittest4result.out
	cat dominion.c.gcov >> hudspero_unittest4result.out

unittestresults: bug1 bug2 bug3 bug4 bug5 bug6 bug7 bug8 bug9 bug10
	./hudspero_unittest_bug1 &> hudspero_unittest1result.out
	gcov dominion.c -b -f >> hudspero_unittest1result.out
	cat dominion.c.gcov >> hudspero_unittest1result.out
	./eckertl_unittest1 &> eckertl_unittest2result.out
	gcov dominion.c -b -f >> eckertl_unittest2result.out
	cat dominion.c.gcov >> eckertl_unittest2result.out
	./hudspero_unittest_bug3 &> hudspero_unittest3result.out
	gcov dominion.c -b -f >> hudspero_unittest3result.out
	cat dominion.c.gcov >> hudspero_unittest3result.out
	./hudspero_unittest_bug4 &> hudspero_unittest4result.out
	gcov dominion.c -b -f >> hudspero_unittest4result.out
	cat dominion.c.gcov >> hudspero_unittest4result.out
	./satherde_unittest1 &> satherde_unittest5result.out
	gcov dominion.c -b -f >> satherde_unittest5result.out
	cat dominion.c.gcov >> satherde_unittest5result.out
	./satherde_unittest2 &> satherde_unittest6result.out
	gcov dominion.c -b -f >> satherde_unittest6result.out
	cat dominion.c.gcov >> satherde_unittest6result.out
	./satherde_unittest3 &> satherde_unittest7result.out
	gcov dominion.c -b -f >> satherde_unittest7result.out
	cat dominion.c.gcov >> satherde_unittest7result.out
	./eckertl_unittest2 &> eckertl_unittest8result.out
	gcov dominion.c -b -f >> eckertl_unittest8result.out
	cat dominion.c.gcov >> eckertl_unittest8result.out
	./eckertl_unittest3 &> eckertl_unittest9result.out
	gcov dominion.c -b -f >> eckertl_unittest9result.out
	cat dominion.c.gcov >> eckertl_unittest9result.out
	./eckertl_unittest4 &> eckertl_unittest10result.out
	gcov dominion.c -b -f >> eckertl_unittest10result.out
	cat dominion.c.gcov >> eckertl_unittest10result.out
	cat hudspero_unittest1result.out eckertl_unittest2result.out hudspero_unittest3result.out hudspero_unittest4result.out satherde_unittest5result.out satherde_unittest6result.out satherde_unittest7result.out eckertl_unittest8result.out eckertl_unittest9result.out eckertl_unittest10result.out > unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe satherde_unittest1 satherde_unittest2 satherde_unittest3 eckertl_unittest1 eckertl_unittest2 eckertl_unittest3 eckertl_unittest4 hudspero_unittest_bug1 hudspero_unittest_bug3 hudspero_unittest_bug4
