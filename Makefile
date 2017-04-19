# COMPILER
CC = gcc

# COMPILER FLAGS
CFLAGS = -Wall

BINPROG = ＡＥＳＴＨＥＴＩＣ
SRCPROG = ＡＥＳＴＨＥＴＩＣ.c

all: $(BINPROG)

$(BINPROG): $(SRCPROG)
	$(CC) $(CFLAGS) -o $(BINPROG) $(SRCPROG)

clean:
	rm $(BINPROG)
