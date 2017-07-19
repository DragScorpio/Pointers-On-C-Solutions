/* 17.10-2 */
#include "dma_queue.h"

int main( void ) {
	char cmd;
	int size, value, flag = 1;

	while( flag ) {
		printf( "indicate a command:\n" );
		printf( "c--->create a queue with a given size\n" );
		printf( "e--->enqueue\n" );
		printf( "d--->dequeue\n" );
		printf( "r--->resize the queue\n" );
		printf( "t--->display the first element\n" );

		scanf( " %c", &cmd );
		switch( cmd ) {
		case 'c':
		case 'C':
			printf( "what's the size? " );
			scanf( " %i", &size );
			assert( create_queue( size ) == 1 );
			break;
		case 'e':
		case 'E':
			printf( "what's the value? " );
			scanf( " %i", &value );
			enqueue( value );
			break;
		case 'd':
		case 'D':
			dequeue();
			break;
		case 'r':
		case 'R':
			printf( "To what size do you want to resize? " );
			scanf( " %i", &size );
			assert( resize_queue( size ) == 1 );
			break;
		case 't':
		case 'T':
			printf( "the first element of the queue is: %i\n", first() );
			break;
		default:
			printf( "illegal command type.\n" );
		}

		printf( "Do you want to continue?[Y/N]  " );
		scanf( " %c", &cmd );
		flag = cmd == 'y' || cmd == 'Y' ? 1 : 0;
	}

	destroy_queue();
	return 0;
}
