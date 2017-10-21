all: node.o library.o main.o
	gcc -o tests node.o main.o library.o

node.o: node.c node.h
	gcc -c node.c

main.o: main.c node.h
	gcc -c main.c

library.o: library.c library.h
	gcc -c library.c

run: all
	./tests

clean:
	rm *.o
