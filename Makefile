# Just a makefile for convenience

CC=g++
CXXFLAGS= -std=c++11 -O2 -g -Wall
LDFLAGS=-g

avengers: Floodfill.o Navigation.o Graph.o

testAll: testEdge testNode testFloodfill 

testNavigation: Navigation.o

testMazecell: mazecell.o
	g++ -isystem ${GTEST_DIR}/include -pthread gtest_main.cc mazecell.o\
		mazecell_unittest.cc libgtest.a -o mazecell_unittest 
	./mazecell_unittest

mazecell.o: mazecell.h

clean: 
	rm -f *.o
