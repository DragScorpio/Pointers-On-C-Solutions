/* 17.10-3 */
#include "llist_queue.h"

static Queue *queue;

void enqueue( QUEUE_TYPE value ) {
	Queue *new_node, **qptr = &queue;
	new_node = (Queue *)malloc( sizeof( Queue ) );
	assert( new_node != NULL );
	new_node->value = value;
	new_node->next = NULL;

	while( *qptr != NULL )
		qptr = &( *qptr )->next;

	*qptr = new_node;
}

void dequeue( void ) {
	Queue *current;
	assert( !is_empty() );

	current = queue;
	queue = queue->next;
	free( current );
	current = NULL;
}

QUEUE_TYPE first( void ) {
	assert( !is_empty() );
	return queue->value;
}

int is_empty( void ) {
	return queue == NULL;
}

void destroy_queue( void ) {
	while( !is_empty() )
		dequeue();
}
