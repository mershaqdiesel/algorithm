OBJDIR=obj
BINDIR=bin
SRCDIR=src
INCDIR=include
TESTDIR=test

CC=clang++
CFLAGS=-std=c++11 -Wall -I$(INCDIR) -O2
LFLAGS=
DFLAGS=-g
OUTPUTAS=-o

TESTCC=g++
TESTCFLAGS=-std=c++11 -Wall -I$(INCDIR) -g
TESTLFLAGS=-lboost_unit_test_framework

OBJECTS=$(addprefix $(OBJDIR)/, )

TESTEXES=$(addprefix $(BINDIR)/, ListTests ArrayTests)

.PHONY: clean

all: release debug tests

release: #$(BINDIR)/algos

debug: #$(BINDIR)/algos_debug

tests: $(TESTEXES)

$(BINDIR)/algos: $(SRCDIR)/main.cpp $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(LFLAGS) $(OUTPUTAS) $@
	
$(BINDIR)/algos_debug: $(SRCDIR)/main.cpp $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(DFLAGS) $(LFLAGS) $(OUTPUTAS) $@
	
$(BINDIR)/%: $(TESTDIR)/%.cpp
	$(TESTCC) $^ $(TESTCFLAGS) $(OUTPUTAS) $@ $(TESTLFLAGS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $^ $(CFLAGS) $(OUTPUTAS) $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $^ $(CFLAGS) $(OUTPUTAS) $@
	
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*

test: $(TESTEXES)
	for exe in $^; do ./$$exe; done