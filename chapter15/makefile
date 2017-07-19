tansaction: inventory.o
	gcc -o transaction inventory.o

inventory.o: inventory.c inventory.h
	gcc -Wall -Werror -c inventory.c

clean:
	rm *.o transaction
