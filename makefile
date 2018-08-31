mainprog.o:Source.cpp
	g++ `pkg-config --cflags opencv` -o test Source.cpp `pkg-config --libs opencv`
