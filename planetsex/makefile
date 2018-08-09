CFLAGS = -ansi -g -Wall

LIBS =  -l stdc++ -lm

CXX = c++

# These lines define what example depends on, and how to make it
example: example.o
		$(CXX) $(CFLAGS) $(LIBS) example.o -o	example

%.o:	%.cc
	$(CXX) $(CFLAGS) 	$< -c	-o $@

%:	%.cc	Makefile
	$(CXX)	$(CFLAGS)	$(LIBS)	$<	-o	$@
