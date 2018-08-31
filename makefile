mainprog.o:test.cpp
	g++ `pkg-config --cflags opencv` -o test test.cpp `pkg-config --libs opencv`
