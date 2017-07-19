/* 17.10-5 & 6 */
#include "arr_bst.h"
#include "dma_queue.h"
#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

void insert( TREE_TYPE value ) {
	int current;
	assert( value != 0 );
	/*
	** assert that value is non-zero,
	** because 0 indicates an unsed node
	*/
	for( current = 1; tree[current] != 0 && current < ARRAY_SIZE; ) {
		if( tree[current] != value )
			current = value < tree[current] ? left_child( current ) : right_child( current );
		else
			break;
	}

	if( current != ARRAY_SIZE )
		tree[current] = value;
}

TREE_TYPE *find( TREE_TYPE value ) {
	int current;
	for( current = 1; tree[current] != value && current < ARRAY_SIZE; ) {
			if( tree[current] != 0 )
				current = value < tree[current] ? left_child( current ) : right_child( current );
			else
				break;
	}

	return tree[current] == value ? tree + current : NULL;
}

int left_child( int current ) {
	return current * 2;
}

int right_child( int current ) {
	return current * 2 + 1;
}

int count( void ) {
	int i, count;
	for( i = 0, count = 0; i < ARRAY_SIZE; i++ )
		if( tree[i] != 0 )
			count++;

	return count;
}

void pre_order_traverse( int parent, void (*callback)( TREE_TYPE value ) ) {
/* parent indicates the index of parent-node in the array */
	int left, right;
	left = left_child( parent );
	right = right_child( parent );

	if( parent < ARRAY_SIZE && tree[parent] != 0 ) {
		callback( tree[parent] );
		pre_order_traverse( left, callback );
		pre_order_traverse( right, callback );
	}
}

void breadth_first_traverse( int parent, void (*callback)( TREE_TYPE value ) ) {
	create_queue( TREE_SIZE );
	enqueue( parent ); /* the queue has the index of each tree's node in the array */

	while( !is_empty() ) {
		parent = first();
		callback( tree[parent] );
		dequeue();

		if( tree[left_child( parent )] != 0 )
			enqueue( left_child( parent ) );

		if( tree[right_child( parent )] != 0 )
			enqueue( right_child( parent ) );
	}
	destroy_queue();
}
