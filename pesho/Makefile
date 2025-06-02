all: findPath.exe
	./findPath.exe

findPath.exe: findPath.c graph.o vector.o
	gcc findPath.c graph.o vector.o -o findPath.exe

extractFile.exe: extractFile.c graph.o
	gcc extractFile.c graph.o -o extractFile.exe
	./extractFile.exe

graph.o: graph.c graph.h
	gcc -c graph.c -o graph.o

vector.o: vector.c vector.h
	gcc -c vector.c -o vector.o

clean:
	del *.exe *.o