prog = testme

all: $(prog)
	./testme

$(prog): testme.c
	gcc -o testme testme.c -coverage 
clean:
	rm $(prog) *.gcno *.gcda *.gcov
