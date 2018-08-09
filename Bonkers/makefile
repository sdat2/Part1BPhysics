CFLAGS = -ansi -g -Wall

LIBS =  -l stdc++ -lm

CXX = c++

# These lines define what Bonk depends on, and how to make it
Bonk: Bonk.o
		$(CXX) $(CFLAGS) $(LIBS) Bonk.o -o	Bonk

%.o:	%.cc
	$(CXX) $(CFLAGS) 	$< -c	-o $@

%:	%.cc	Makefile
	$(CXX)	$(CFLAGS)	$(LIBS)	$<	-o	$@
