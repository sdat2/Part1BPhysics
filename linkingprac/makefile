# Makefile for package1 and package2

CFLAGS = -ansi -g -Wall

LIBS = -l stdc++ -lm

CXX = c++

# These lines define what package1 depends on, and how to make it
package1:	package1.o	tinyutils.o
		$(CXX) $(CFLAGS) $(LIBS) package1.o	tinyutils.o	tinyutils.h	-o	package1
package2:	package2.o	tinyutils2.o
		$(CXX) $(CFLAGS) $(LIBS) package2.o	tinyutils2.o	-o	package2

%.o:	%.cc
	$(CXX) $(CFLAGS) 	$< -c	-o $@

%:	%.cc	Makefile
	$(CXX)	$(CFLAGS)	$(LIBS)	$<	-o	$@
