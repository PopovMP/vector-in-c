OBJDIR = obj
SRCDIR = src

OBJ = $(OBJDIR)/vector.o $(OBJDIR)/test.o

CC     = /usr/bin/gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11

test : $(OBJ)
	$(CC) -o $@ $(OBJ)

$(OBJDIR)/vector.o : $(SRCDIR)/vector.c $(SRCDIR)/vector.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/test.o : $(SRCDIR)/test.c $(SRCDIR)/vector.h
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJ) test

