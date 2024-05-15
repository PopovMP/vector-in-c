OBJDIR = obj
SRCDIR = src

OBJ = $(OBJDIR)/vector.o $(OBJDIR)/test.o

CC  = /usr/bin/gcc
OPT = -Wall -Wextra -Wpedantic
STD = -std=c11

test : $(OBJ)
	$(CC) -o test $(OBJ)

$(OBJDIR)/vector.o : $(SRCDIR)/vector.c
	$(CC) $(OPT) $(STD) -c -o $@ $<

$(OBJDIR)/test.o : $(SRCDIR)/test.c
	$(CC) $(OPT) $(STD) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJ) test

