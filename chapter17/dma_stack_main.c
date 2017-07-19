/* 17.10-1 */
#include "dma_stack.h"
#include <stdio.h>
#include <assert.h>

int main( void ) {
	char cmd;
	int size, value, flag = 1;

	while( flag ) {
		printf( "indicate a command:\n" );
		printf( "c--->create a stack with given size\n" );
		printf( "a--->add new value to the stack\n" );
		printf( "d--->delete a value from the stack\n" );
		printf( "r--->resize the stack\n" );
		printf( "t--->display the topmost element\n" );

		scanf( " %c", &cmd );
		switch( cmd ) {
		case 'c':
		case 'C':
			printf( "what's the size? " );
			scanf( " %i", &size );
			assert( create_stack( size ) == 1 );
			break;
		case 'a':
		case 'A':
			printf( "what's the value? " );
			scanf( " %i", &value );
			push( value );
			break;
		case 'd':
		case 'D':
			pop();
			break;
		case 'r':
		case 'R':
			printf( "To what size do you want to resize? " );
			scanf( " %i", &size );
			assert( resize_stack( size ) );
			break;
		case 't':
		case 'T':
			printf( "the element at the top of stack is: %i\n", top() );
			break;
		default:
			printf( "illegal command type.\n" );
		}

		printf( "Do you want to continue?[Y/N]  " );
		scanf( " %c", &cmd );
		flag = cmd == 'y' || cmd == 'Y' ? 1 : 0;
	}

	destroy_stack();
	return 0;
}
