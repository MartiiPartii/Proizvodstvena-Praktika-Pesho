all: main.exe
	./main.exe

main.exe: main.c findPath.o extractFile.o graph.o vector.o
	gcc main.c findPath.o extractFile.o graph.o vector.o -o main.exe

extractFile.exe: functionality/extractFile/extractFile.c functionality/extractFile/extractFile.h graph.o
	gcc functionality/extractFile/extractFile.c graph.o -o extractFile.exe
	./extractFile.exe

findPath.o: functionality/findPath/findPath.c
	gcc -c functionality/findPath/findPath.c -o findPath.o

extractFile.o: functionality/extractFile/extractFile.c
	gcc -c functionality/extractFile/extractFile.c -o extractFile.o

graph.o: dataStructures/graph/graph.c dataStructures/graph/graph.h
	gcc -c dataStructures/graph/graph.c -o graph.o

vector.o: dataStructures/vector/vector.c dataStructures/vector/vector.h
	gcc -c dataStructures/vector/vector.c -o vector.o

clean:
	del *.exe *.o