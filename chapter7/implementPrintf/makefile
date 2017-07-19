main: main.o printf.o
	gcc -o main main.o printf.o

main.o: main.c printf.h
	gcc -c main.c

printf.o: printf.c printf.h
	gcc -c printf.c

clean:
	rm -f *.o main
