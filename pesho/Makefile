all: findPath.exe
	./findPath.exe

findPath.exe: findPath.c graph.o vector.o queue.o
	gcc findPath.c graph.o queue.o vector.o -o findPath.exe

graph.o: graph.c graph.h
	gcc -c graph.c -o graph.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o

vector.o: vector.c vector.h
	gcc -c vector.c -o vector.o

clean:
	del *.exe *.o