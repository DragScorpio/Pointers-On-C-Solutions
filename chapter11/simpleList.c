/* 11.11-4 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} NODE;

/* implementation */
NODE* implement_node( NODE *head ) {
	head = malloc( sizeof( NODE ) );
	head->value = -1;
	printf( "implemented node 0\n" );
	/* allocate a NODE's space for head node */

	NODE *next_node = head;
	int i;
	if( head != NULL ) {
		for( i = 0; i < 3; i++ ) {
			next_node->next = malloc( sizeof( NODE ) );
			if( next_node->next != NULL ) {
				next_node->next->value = i * 5;
				next_node = next_node->next;
				printf( "implemented node %d\n", i + 1 );
			}
			else
				return NULL;
		}
		next_node->next = malloc( sizeof( NODE ) );
		if( next_node->next != NULL ) {
			next_node = next_node->next;
			next_node->next = NULL;
			next_node->value = i * 5;
			printf( "implemented node %d\n", i + 1 );
		}
		else
			return NULL;
	}

	return head;
}

void free_node( NODE *head ) { /* recursively free memory */
	if( head->next != NULL )
		free_node( head->next );

	printf( "freed node's value: %d\n", head->value );
	free( head );
}

void print_node( NODE *head ) { /* recursively print node's value */
	if( head != NULL ) {
		printf( "%d\n", head->value );
		print_node( head->next );
	}
}

int main( void ) {
	NODE *head;
	head = implement_node( head );
	print_node( head );
	free_node( head );

	return 0;
}
