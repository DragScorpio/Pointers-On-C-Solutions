/* 17.10-4 */
#include "multi_stack.h"

int main( void ) {
	char cmd;
	int size, index, value, flag = 1;

	while( flag ) {
		printf( "indicate a command:\n" );
		printf( "c--->create a stack with given size\n" );
		printf( "i--->insert a new value to a stack\n" );
		printf( "d--->delete a value from a stack\n" );
		printf( "r--->resize a stack\n" );
		printf( "s--->show the topmost element of a stack\n" );

		scanf( " %c", &cmd );
		switch( cmd ) {
		case 'c':
		case 'C':
			printf( "what's the index of this stack?  " );
			scanf( " %i", &index );
			printf( "what's the size of this stack?  " );
			scanf( " %i", &size );
			assert( create_stack( size, index ) == 1 );
			break;
		case 'i':
		case 'I':
			printf( "what's the index of this stack?  " );
			scanf( " %i", &index );
			printf( "what's the value to insert?  " );
			scanf( " %i", &value );
			push( value, index );
			break;
		case 'd':
		case 'D':
			printf( "what's the index of this stack?  " );
			scanf( " %i", &index );
			pop( index );
			break;
		case 'r':
		case 'R':
			printf( "what's the index of this stack?  " );
			scanf( " %i", &index );
			printf( "To what size do you want to resize? " );
			scanf( " %i", &size );
			assert( resize_stack( size, index ) );
			break;
		case 's':
		case 'S':
			printf( "what's the index of this stack?  " );
			scanf( " %i", &index );
			printf( "the element at the top of stack is: %i\n", top( index ) );
			break;
		default:
			printf( "illegal command type.\n" );
		}

		printf( ">>>>>Do you want to continue?[Y/N]  " );
		scanf( " %c", &cmd );
		flag = cmd == 'y' || cmd == 'Y' ? 1 : 0;
	}

	for( index = 0; !is_empty( index ); index++ )
		destroy_stack( index );

	return 0;
}
