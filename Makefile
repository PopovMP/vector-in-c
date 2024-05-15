OBJDIR = obj
SRCDIR = src

BIN = main
OBJ = $(OBJDIR)/vector.o $(OBJDIR)/main.o

CC   = /usr/bin/gcc
WARN = -Wall -Wextra -Wpedantic
STD  = -std=c11

all : $(BIN)

$(BIN) : $(OBJ)
	$(CC) -o $@ $(OBJ)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(WARN) $(STD) -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJ) $(BIN)

