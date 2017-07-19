/* 17.10-5 & 6 */
#ifndef _ARR_BST
#define _ARR_BST

#include <stdio.h>
#include <assert.h>
#define TREE_TYPE int

void insert( TREE_TYPE value );
TREE_TYPE *find( TREE_TYPE value );
int left_child( int current );
int right_child( int current );
int count( void );
void pre_order_traverse( int parent, void (*callback)( TREE_TYPE value ) );
void breadth_first_traverse( int parent, void (*callback)( TREE_TYPE value ) );

#endif
