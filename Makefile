CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: main tests

main: cipher.o main.o
	$(CC) $(CFLAGS) -o main cipher.o main.o

tests: cipher.o tests.o
	$(CC) $(CFLAGS) -o tests cipher.o tests.o

cipher.o: cipher.c cipher.h
	$(CC) $(CFLAGS) -c cipher.c

main.o: main.c cipher.h
	$(CC) $(CFLAGS) -c main.c

tests.o: tests.c cipher.h
	$(CC) $(CFLAGS) -c tests.c

clean:
	rm -f main tests *.o

