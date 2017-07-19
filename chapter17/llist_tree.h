/* 17.10-9 & 10 */
#ifndef _LLIST_TREE
#define _LLIST_TREE

#define TREE_TYPE int
typedef struct BINARY_SEARCH_TREE {
	TREE_TYPE value;
	struct BINARY_SEARCH_TREE *left;
	struct BINARY_SEARCH_TREE *right;
} BST;

void insert( TREE_TYPE value );
BST **find( TREE_TYPE value );
void in_order_traverse( void (*callback)( void *node ) );
void pre_order_traverse( void (*callback)( void *node ) );
void post_order_traverse( void (*callback)( void *node ) );
void print_node( void *node );
void destroy_tree( void );
void delete( TREE_TYPE value );

#endif
