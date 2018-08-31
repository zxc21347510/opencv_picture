mainprog.o:test.cpp
	g++ `pkg-config --cflags opencv` -o t test.cpp `pkg-config --libs opencv`
