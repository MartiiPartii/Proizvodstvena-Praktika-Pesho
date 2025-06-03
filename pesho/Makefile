all: findPath.exe
	./findPath.exe

findPath.exe: findPath.c graph.o vector.o
	gcc findPath.c graph.o vector.o -o findPath.exe

extractFile.exe: extractFile.c graph.o
	gcc extractFile.c graph.o -o extractFile.exe
	./extractFile.exe

graph.o: dataStructures/graph/graph.c dataStructures/graph/graph.h
	gcc -c dataStructures/graph/graph.c -o graph.o

vector.o: dataStructures/vector/vector.c dataStructures/vector/vector.h
	gcc -c dataStructures/vector/vector.c -o vector.o

clean:
	del *.exe *.o