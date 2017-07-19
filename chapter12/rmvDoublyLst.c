/* 12.8-6 */
#include <stdio.h>
#include <stdlib.h>
#define MEM_DEFICIT "Not enough memory is available"
struct NODE {
	struct NODE *prev;
	struct NODE *next;
	int value;
};

int  dll_remove   ( struct NODE **rootPtr, struct NODE *node );
int  dll_implement( struct NODE **rootPtr, int n_nodes );
void dll_print    ( struct NODE *root );
void dll_free     ( struct NODE *root );

int main( void ) {
	struct NODE **rootPtr;
	struct NODE *node;
	int i, n_nodes;

	printf( "How many nodes do you wanna implement? " );
	scanf( "%d", &n_nodes );
	if( n_nodes < 0 )
		return 1;

	if( dll_implement( rootPtr, n_nodes ) ) {
		dll_print( *rootPtr );
		printf( "Which node do you wanna delete? " );
		scanf( "%d", &i );

		node = *rootPtr;
		while( node != NULL && i-- > 0 )
			node = node->next;

		if( dll_remove( rootPtr, node ) )
			dll_print( *rootPtr );
		else
			printf( "No such node exists.\n" );
	}

	dll_free( *rootPtr );
	return 0;
}

int dll_remove( struct NODE **rootPtr, struct NODE *node ) {
	struct NODE *current; /* current pinpoints the node to delete */

	while( ( current = (*rootPtr)->next ) != NULL && current != node )
		rootPtr = &(*rootPtr)->next;

	if( current == NULL ) /* searched through dll and node is not found */
		return 0;

	if( current->next != NULL )
		current->next->prev = *rootPtr;

	(*rootPtr)->next = current->next;
	free( current );
	current = NULL;
	return 1;
}

int dll_implement( struct NODE **rootPtr, int n_nodes ) {
	struct NODE *head;
	int value;

	*rootPtr = (struct NODE *)malloc( sizeof( struct NODE ) );
	if( *rootPtr == NULL )
		return 0;

	head = *rootPtr;
	while( n_nodes-- > 0 ) {
		head->next = (struct NODE *)malloc( sizeof( struct NODE ) );
		if( head->next == NULL ) {
			printf( "%s\n", MEM_DEFICIT );
			exit( EXIT_FAILURE );
		}

		printf( "Enter the value of the next node: " );
		scanf( "%d", &value );
		head->next->value = value;
		head->next->prev = head;
		head = head->next;
	}
	(*rootPtr)->prev = head;
	head->next = NULL;

	return 1;
}

void dll_print( struct NODE *root ) {
	while( ( root = root->next ) != NULL )
		printf( "%d\n", root->value );
}

void dll_free( struct NODE *root ) {
	while( ( root = root->next ) != NULL ) {
		free( root->prev );
		root->prev = NULL;
	}
}
