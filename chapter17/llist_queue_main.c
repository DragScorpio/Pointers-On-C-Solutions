/* 17.10-3 */
#include "llist_queue.h"

int main( void ) {
	char cmd;
	int value, flag = 1;

	while( flag ) {
		printf( "indicate a command:\n" );
		printf( "e--->enqueue\n" );
		printf( "d--->dequeue\n" );
		printf( "p--->print first element\n" );

		scanf( " %c", &cmd );
		switch( cmd ) {
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
		case 'p':
		case 'P':
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
