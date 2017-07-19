/* 12.8-1, 2 */
#include <stdio.h>
#include <stdlib.h>

typedef struct SINGLY_NODE {
	struct SINGLY_NODE *next;
	int value;
} Node;

int implement_list( Node *rootp, int n_nodes ) {
	Node *current;
	int i = 0;

	for( current = rootp, i = 0; i < n_nodes; i++, current = current->next ) {
		if( current == NULL ) {
			printf( "Not enough memory to be allocated...\n" );
			return 0;
		}
		printf( "Please enter the next node's value: " );
		scanf( "%d", &current->value );

		current->next = ( i == n_nodes - 1 ) ? NULL : (Node *)malloc( sizeof( Node ) );

	}

	return 1;
}

void clear_list( Node *rootp ) {
	if( rootp->next != NULL )
		clear_list( rootp->next );

	free( rootp );
/*
	Node *cur;
	while ((cur = rootp) != NULL) { // set curr to head, stop if list empty.
                rootp = rootp->next;          // advance head to next element.
                free (cur);                // delete saved pointer.
        }
*/
}

Node *search_list( Node *rootp, int value ) {
	while( rootp != NULL && rootp->value != value )
		rootp = rootp->next;

	return rootp;
}

int count_list( Node *rootp ) {
	int i = 1;
	Node *current = rootp;

	while( ( current = current->next ) != NULL )
		i++;

	return i;
}

int main( void ) {
	Node *root, *target;
	int n_nodes, value;
	root = (Node *)malloc( sizeof( Node ) );
	if( root == NULL )
		return 0;

	printf( "Please enter how many nodes: " );
	scanf( "%d", &n_nodes );
	if( implement_list( root, n_nodes ) )
		printf( "There are %d nodes in the list\n", count_list( root ) );

	printf( "What value to search? " );
	scanf( "%d", &value );

	if( ( target = search_list( root, value ) ) != NULL )
		printf( "The value %d is found!\n", target->value );
	else
		printf( "Value is not found\n" );

	clear_list( root );
	return 0;
}
