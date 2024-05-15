
CC = /usr/bin/gcc

OBJ = vector.o test.o

OPT = -Wall -Wextra -Wpedantic

STD = -std=c11

test : $(OBJ)
	$(CC) -o test $(OBJ)

vector.o : vector.c vector.h
	$(CC) $(OPT) $(STD) -c vector.c

test.o : test.c vector.h
	$(CC) $(OPT) $(STD) -c test.c

.PHONY : clean
clean :
	rm -f $(OBJ)

