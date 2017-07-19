/* 17.10-9 & 10 */
#include "llist_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define XOR( X, Y ) (X) != (Y)

static BST *tree;

void insert( TREE_TYPE value ) {
	BST *new_node, **node_ptr;
	new_node = (BST *)malloc( sizeof(BST) );
	assert( new_node != NULL );
	new_node->value = value;
	new_node->left = new_node->right = NULL;

	node_ptr = &tree;
	while( *node_ptr != NULL ) {
		assert( (*node_ptr)->value != value );
		node_ptr = value < (*node_ptr)->value ? &(*node_ptr)->left : &(*node_ptr)->right;
	}

	*node_ptr = new_node;
}

/* helper function */
static int is_leaf( BST *node ) {
	assert( node != NULL );
	return node->left == NULL && node->right == NULL ? 1 : 0;
}

/* helper function */
static int has_one_child( BST *node ) {
	assert( node != NULL );
	return XOR( node->left == NULL, node->right == NULL );
}

static void in_order( BST *root, void (*callback)( void *node ) ) {
	if( root != NULL ) {
		in_order( root->left, callback );
		callback( root );
		in_order( root->right, callback );
	}
}

static void pre_order( BST *root, void (*callback)( void *node ) ) {
	if( root != NULL ) {
		callback( root );
		pre_order( root->left, callback );
		pre_order( root->right, callback );
	}
}

static void post_order( BST *root, void (*callback)( void *node ) ) {
	if( root != NULL ) {
		post_order( root->left, callback );
		post_order( root->right, callback );
		callback( root );
	}
}

BST **find( TREE_TYPE value ) {
	BST **current;
	current = &tree;
	while( *current != NULL && (*current)->value != value )
		current = value < (*current)->value ? &(*current)->left : &(*current)->right;

	return current;
}

void in_order_traverse( void (*callback)( void *node ) ) {
	in_order( tree, callback );
}

void pre_order_traverse( void (*callback)( void *node ) ) {
	pre_order( tree, callback );
}

void post_order_traverse( void (*callback)( void *node ) ) {
	post_order( tree, callback );
}

void print_node( void *node ) {
	assert( node != NULL );
	printf( "[%i] ", ( (BST *)node )->value );
}

void destroy_tree( void ) {
	post_order( tree, free );
}

static BST **in_order_successor( BST **root ) {
/* this function returns the in-order successor of the node pointed by root */
	assert( *root != NULL && (*root)->right != NULL );
	root = &(*root)->right;
	while( (*root)->left != NULL )
		root = &(*root)->left;

	return root;
}

void delete( TREE_TYPE value ) {
/*
** case 1: the node to be deleted is a leaf---> delete it directly
** case 2: the node has one child---> the child inherits the node, and then delete the node
** case 3: the node has two children---> find the in-order successor of the node, which MUST BE a leaf,
** 	   and then copy the value of this leaf to the target node. Finally, delete this leaf node.
*/
	BST **node_ptr, **successor, *temp;
	node_ptr = find( value );
	assert( *node_ptr != NULL );  /* the value must firstly belong to a node in the BST */

	if( is_leaf( *node_ptr ) ) {		/* case 1 */
		free( *node_ptr );
		*node_ptr = NULL;
	}
	else if( has_one_child( *node_ptr ) ) { /* case 2 */
		temp = *node_ptr;
		*node_ptr = (*node_ptr)->left != NULL ? (*node_ptr)->left : (*node_ptr)->right;
		free( temp );
		temp = NULL;
	}
	else {					/* case 3 */
		successor = in_order_successor( node_ptr );
		/* successor has no left_child, but possibly has right_child */
		(*node_ptr)->value = (*successor)->value; /* copy value to root */

		temp = *successor;
		*successor = (*successor)->right;
		free( temp );
		temp = NULL;
	}
}
