# Makefile for package1 and package2

CFLAGS = -ansi -g -Wall

LIBS = -l stdc++ -lm

CXX = c++

# These lines define what package1 depends on, and how to make it
big:	big.o small.o
		$(CXX) $(CFLAGS) $(LIBS) big.o small.o -o	big

%.o:	%.cc
	$(CXX) $(CFLAGS) 	$< -c	-o $@

%:	%.cc	Makefile
	$(CXX)	$(CFLAGS)	$(LIBS)	$<	-o	$@
