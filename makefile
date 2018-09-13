mainprog.o:source.cpp
	g++ `pkg-config --cflags opencv` -o t source.cpp `pkg-config --libs opencv`

