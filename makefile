OBJDIR=obj
BINDIR=bin
SRCDIR=src
INCDIR=include
TESTDIR=test

CC=g++
CFLAGS=-std=c++11 -Wall
CCFLAGS=-c -I$(INCDIR)
LFLAGS=
DFLAGS=-g -v
OUTPUTAS=-o

TESTCC=g++
TESTCFLAGS=-std=c++11 -Wall -I$(INCDIR) -g
TESTLFLAGS=-lboost_unit_test_framework

OBJECTS=$(addprefix $(OBJDIR)/, )

TESTEXES=$(addprefix $(BINDIR)/, ListTests ArrayTests)

.PHONY: clean

all: release tests

release: $(BINDIR)/rpcalc

debug: $(BINDIR)/rpcalc_debug

tests: $(TESTEXES)

$(BINDIR)/rpcalc: $(OBJDIR)/rpcalc.o
	$(CC) $^ $(CFLAGS) $(LFLAGS) $(OUTPUTAS) $@
	
$(BINDIR)/rpcalc_debug: $(OBJDIR)/rpcalc_debug.o
	$(CC) $^ $(CFLAGS) $(DFLAGS) $(LFLAGS) $(OUTPUTAS) $@
	
$(BINDIR)/%: $(TESTDIR)/%.cpp
	$(TESTCC) $^ $(TESTCFLAGS) $(OUTPUTAS) $@ $(TESTLFLAGS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $^ $(CFLAGS) $(CCFLAGS) $(OUTPUTAS) $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $^ $(CFLAGS) $(OUTPUTAS) $@
	
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*

test: $(TESTEXES)
	for exe in $^; do ./$$exe; done