main: main.o BMP.o
	g++ test.o BMP.o -o main
	./test
main.o: main.cpp BMP.h
	g++ -Wall -c main.cpp 
BMP.o: BMP.cpp BMP.h
	g++ -Wall -c BMP.cpp
clean:
	rm -rf *.o main
