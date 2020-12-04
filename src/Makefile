CC=g++

all: Application
	
Application: main.o func.o
	$(CC) V1.0.o funkcijos.o -o Application

main.o: V1.0.cpp funkcijos.h
	$(CC) -c ND2_v1.0.cpp Header.h

func.o: funkcijos.cpp funkcijos.h struktura.h
	$(CC) -c funkcijos.cpp funkcijos.h struktura.h

clean:
	rm *.o *.gch Application
