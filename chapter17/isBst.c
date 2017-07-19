/* 17.10-7 */
/* in this question, the isBST( int ) is partially correct; it is discarded as an experiment */
#include "dma_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TREE_TYPE int

static int tree_size;
static TREE_TYPE *tree;

void init_binary_tree( int height ) {
/* user fills in each node of a binary tree by giving height first */
	int i, size, width, value;
	assert( height > 0 && tree == NULL );
	/* height of binary tree must be positive; tree can only be created once */
	/* calculate the right size of array to accommodate the binary tree */
	for( i = 0, size = 0, width = 1; i < height; i++ ) {
		width *= ( i == 0 ? 1 : 2 );
		size += width;
	}

	tree_size = size;
	tree = (TREE_TYPE *)calloc( tree_size + 1, sizeof( TREE_TYPE ) );

	for( i = 1; i < tree_size + 1; i++ ) {
		/* enter 0 if the node does not exist */
		printf( "Enter the next value: " );
		scanf( " %i", &value );
		tree[i] = value;
	}
}

int left_child( int current ) {
	return 2 * current;
}

int right_child( int current ) {
	return 2 * current + 1;
}

int compare( int left, int parent, int right ) {
	if( left < tree_size + 1 && tree[left] != 0 ) {
		if( tree[left] >= tree[parent] )
			return 0;
	}

	if( right < tree_size + 1 && tree[right] != 0 ) {
		if( tree[right] <= tree[parent] )
			return 0;
	}

	return 1;
}

int isBST( int parent, int (*callback)( int, int, int ) ) {
/* conduct in-order traverse to examine BST relation */
	int left, right;
	left = left_child( parent );
	right = right_child( parent );

	if( parent < tree_size + 1 && tree[parent] != 0 ) {
		if( isBST( left, callback ) == 0 )
			return 0;

		if( isBST( right, callback ) == 0 )
			return 0;

		return callback( left, parent, right );
	}

	return 1;
}

void destroy_tree( void ) {
	free( tree );
	tree = NULL;
}

void in_order_traverse( int parent ) {
/* in-order traverse to store tree nodes to a queue */
	if( parent < ( tree_size + 1 ) && tree[parent] != 0 ) {
		in_order_traverse( left_child( parent ) );
		enqueue( tree[parent] );
		in_order_traverse( right_child( parent ) );
	}
}

int isBST_corrected( void ) {
/* argument: size of queue */
	TREE_TYPE previous;
	create_queue( tree_size + 1 );
	in_order_traverse( 1 );

	while( !is_empty() ) {
		previous = first();
		dequeue();
		if( !is_empty() && previous >= first() )
			return 0;
	}

	return 1;
}

int main( void ) {
	int height;
	printf( "what's the height of the tree? " );
	scanf( " %i", &height );
	init_binary_tree( height );
/*
	printf( isBST( 1, compare ) ? "Yes, it is BST\n" : "No, it isn't BST\n" );
*/

	printf( isBST_corrected() ? "Yes, it is BST\n" : "No, it isn't BST\n" );
	destroy_tree();
	destroy_queue();
	return 0;
}
