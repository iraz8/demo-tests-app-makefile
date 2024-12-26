CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lcunit

all: main

main: main.o sum.o
	$(CC) $(CFLAGS) -o main main.o sum.o

main.o: main.c sum.h
	$(CC) $(CFLAGS) -c main.c

sum.o: sum.c sum.h
	$(CC) $(CFLAGS) -c sum.c

test: test_sum
	./test_sum

test_sum: test_sum.o sum.o
	$(CC) $(CFLAGS) -o test_sum test_sum.o sum.o $(LIBS)

test_sum.o: test_sum.c sum.h
	$(CC) $(CFLAGS) -c test_sum.c

clean:
	rm -f *.o main test_sum
