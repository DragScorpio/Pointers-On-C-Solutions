main: main.o increment.o negate.o
	gcc -o main main.o increment.o negate.o

main.o: main.c increment.h negate.h
	gcc -c main.c

increment.o: increment.c increment.h
	gcc -c increment.c

negate.o: negate.c negate.h
	gcc -c negate.c

clean:
	rm -f *.o main
