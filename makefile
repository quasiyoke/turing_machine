CC=gcc
LFLAGS=-Wall
CFLAGS=-x c -std=c99 -Wall -D_XOPEN_SOURCE

ODIR=obj

BDIR=bin
EXECUTABLE=$(BDIR)/turing_machine

TDIR=tests

all: $(EXECUTABLE)

$(EXECUTABLE): $(ODIR)/main.o $(ODIR)/turing_machine.o | $(BDIR)/
	$(CC) -o $@ $^ $(LFLAGS)

$(ODIR)/main.o: src/main.c | $(ODIR)/
	$(CC) -c $(CFLAGS) -o $@ $^

$(ODIR)/turing_machine.o: src/turing_machine.c | $(ODIR)/
	$(CC) -c $(CFLAGS) -o $@ $^

$(BDIR)/:
	mkdir -p $@

$(ODIR)/:
	mkdir -p $@

clean:
	rm -fr $(ODIR) $(BDIR) $(TDIR)/*_result
