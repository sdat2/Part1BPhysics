CFLAGS = -g -Wall

LIBS =  -l stdc++ -lm

CXX = c++

# These lines define what AllStrings depends on, and how to make it
AllStrings: AllStrings.o
		$(CXX) $(CFLAGS) $(LIBS) AllStrings.o -o	AllStrings
Twos: Twos.o
				$(CXX) $(CFLAGS) $(LIBS) Twos.o -o	Twos
FactorialCalculator: FactorialCalculator.o
		$(CXX) $(CFLAGS) $(LIBS) FactorialCalculator.o -o	FactorialCalculator
PrintWithCommas: PrintWithCommas.o
		$(CXX) $(CFLAGS) $(LIBS) PrintWithCommas.o -o	PrintWithCommas
particle: particle.o
		$(CXX) $(CFLAGS) $(LIBS) particle.o -o	particle
particle1: particle1.o
		$(CXX) $(CFLAGS) $(LIBS) particle1.o -o	particle1

%.o:	%.cc
	$(CXX) $(CFLAGS) 	$< -c	-o $@

%:	%.cc	Makefile
	$(CXX)	$(CFLAGS)	$(LIBS)	$<	-o	$@
