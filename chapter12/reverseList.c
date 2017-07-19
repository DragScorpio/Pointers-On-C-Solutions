/* 12.8-4 */
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
}

Node *sll_reverse( Node *root ) {
	Node *previous, *current, *next;

	for( previous = NULL, current = root, next = current->next; next != NULL;
	     previous = current, current = next, next = next->next )
		current->next = previous;

	current->next = previous;
	return current;
}

void print_list( Node *root ) {
	while( root != NULL ) {
		printf( "%d\n", root->value );
		root = root->next;
	}
}

int main( void )  {
	int n_nodes;
	Node *root = (Node *)malloc( sizeof( Node ) );
	if( root == NULL )
		return 0;

	printf( "How many nodes are there? " );
	scanf( "%d", &n_nodes );
	if( implement_list( root, n_nodes ) ) {
		print_list( root );
		root = sll_reverse( root );
		print_list( root );
	}

	clear_list( root );
	return 0;
}
