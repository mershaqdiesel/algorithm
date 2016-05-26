OBJDIR=obj
BINDIR=bin
SRCDIR=src
INCDIR=include

CC=clang++
CFLAGS=-std=c++11 -Wall -I$(INCDIR) -O2
LFLAGS=
DFLAGS=-g
OUTPUTAS=-o

OBJECTS=$(addprefix $(OBJDIR)/, )

.PHONY : all release debug clean

all: release debug

release: $(BINDIR)/algos

debug: $(BINDIR)/algos_debug

$(BINDIR)/algos: $(SRCDIR)/main.cpp $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(LFLAGS) $(OUTPUTAS) $@
	
$(BINDIR)/algos_debug: $(SRCDIR)/main.cpp $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(DFLAGS) $(LFLAGS) $(OUTPUTAS) $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $^ $(CFLAGS) $(OUTPUTAS) $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $^ $(CFLAGS) $(OUTPUTAS) $@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*