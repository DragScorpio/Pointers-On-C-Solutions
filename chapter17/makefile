all: genericStack

genericStack: test_generic_stack.o
	gcc -o genericStack test_generic_stack.o

test_generic_stack.o: test_generic_stack.c generic_stack.h
	gcc -Wall -Werror -c test_generic_stack.c

clean:
	rm -f *.o genericStack
