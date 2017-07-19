/* 17.10-5 & 6*/
#include "arr_bst.h"
#include "dma_queue.h"
void print_tree( int value ) {
	printf( "%i ", value );
}

int main( void ) {
	char cmd;
	int value, flag = 1;
	int *node;

	while( flag ) {
		printf( "***i: insert a new node to the tree***\n" );
		printf( "***f: find a value from the tree***\n" );
		printf( "***c: count the number of nodes in the tree***\n" );
		printf( "***p: print tree's nodes in pre-order***\n" );
		printf( "***b: print three's node in breadth-first-order***\n" );
		scanf( " %c", &cmd );

		switch( cmd ) {
		case 'i':
		case 'I':
			printf( "Enter a value for the new node: " );
			scanf( " %i", &value );
			insert( value );
			break;
		case 'f':
		case 'F':
			printf( "Enter the value to find: " );
			scanf( " %i", &value );
			if( ( node = find( value ) ) != NULL )
				printf( "The value %i is found\n", *node );
			else
				printf( "The value is not found!\n" );
			break;
		case 'c':
		case 'C':
			printf( "There are %i nodes in the tree\n", count() );
			break;
		case 'p':
		case 'P':
			pre_order_traverse( 1, print_tree );
			printf( "\n" );
			break;
		case 'b':
		case 'B':
			breadth_first_traverse( 1, print_tree );
			printf( "\n" );
			break;
		default:
			printf( "Illegal cmd detected!\n" );

		}

		printf( "Do you want to continue: [Y/N] " );
		scanf( " %c", &cmd );
		flag = cmd == 'Y' || cmd == 'y' ? 1 : 0;
	}

	destroy_queue();
	return 0;
}
