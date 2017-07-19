/* 12.8-5 */
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

void print_list( Node *rootp ) {
	while( rootp != NULL ) {
		printf( "%d\n", rootp->value );
		rootp = rootp->next;
	}
}

int sll_remove( Node **rootp, Node *node ) {
	Node* previous = NULL;

	while( *rootp != NULL ) {
		if( *rootp == node )
			break;

		previous = *rootp;
		rootp = &previous->next;
	}

	if( *rootp == NULL ) /* if node is not found */
		return 0;

	/* else, the node is found definitely */
	if( previous == NULL ) /* remove the first node */
		*rootp = node->next;
	else
		previous->next = node->next;

	free( node );
	node = NULL;
	return 1;
}

int main( void ) {
	int i, n_nodes;
	Node *node;
	Node *root = (Node *)malloc( sizeof( Node ) );
	if( root == NULL )
		return 0;

	printf( "How many nodes in the list? " );
	scanf( "%d", &n_nodes );
	if( implement_list( root, n_nodes ) )
		print_list( root );

	printf( "Which node to delete? ( n represents for the nth node ) " );
	scanf( "%d", &i );
	for( node = root; --i > 0; )
		node = node->next;

	sll_remove( &root, node );
	print_list( root );
	return 0;
}
