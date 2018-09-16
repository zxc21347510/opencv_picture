mainprog.o:stitching.cpp
	g++ `pkg-config --cflags opencv` -o t stitching.cpp `pkg-config --libs opencv`

