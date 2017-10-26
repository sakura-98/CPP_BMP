test: test.o BMP.o
	g++ test.o BMP.o -o main
	./test
test.o: test.cpp BMP.h
	g++ -Wall -c test.cpp 
BMP.o: BMP.cpp BMP.h
	g++ -Wall -c BMP.cpp
clean:
	rm -rf *.o
