CC=gcc
LFLAGS=-Wall
CFLAGS=-x c -std=c99 -Wall

ODIR=obj

BDIR=bin
EXECUTABLE=$(BDIR)/turing_machine

all: $(EXECUTABLE)

$(ODIR)/main.o: src/main.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(ODIR)/turing_machine.o: src/turing_machine.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(EXECUTABLE): $(ODIR)/main.o $(ODIR)/turing_machine.o
	$(CC) -o $@ $^ $(LFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*
