mainprog.o:Source.cpp
	g++ `pkg-config --cflags opencv` -o t Source.cpp `pkg-config --libs opencv`
