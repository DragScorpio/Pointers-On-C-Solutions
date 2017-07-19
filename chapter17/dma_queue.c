/* 17.10-2 */
#include "dma_queue.h"
#define ARRAY_SIZE ( queue_size + 1 )
static size_t queue_size;
static int front = 1;
static int rear = 0;
static QUEUE_TYPE *queue;

int create_queue( size_t size ) {
	assert( queue_size == 0 );  /* queue is created if only queue is empty currently */
	queue_size = size;
	queue = (QUEUE_TYPE *)calloc( ARRAY_SIZE, sizeof( QUEUE_TYPE ) );
	return queue != NULL ? 1 : 0;
}

void enqueue( QUEUE_TYPE value ) {
	assert( !is_full() );
	rear = ( rear + 1 ) % ARRAY_SIZE;
	queue[rear] = value;
}

void dequeue( void ) {
	assert( !is_empty() );
	front = ( front + 1 ) % ARRAY_SIZE;
}

QUEUE_TYPE first( void ) {
	assert( !is_empty() );
	return queue[front];
}

int is_empty( void ) {
	return ( rear + 1 ) % ARRAY_SIZE == front;
}

int is_full( void ) {
	return ( rear + 2 ) % ARRAY_SIZE == front;
}

int resize_queue( size_t new_size ) {
	assert( new_size > queue_size );
	queue_size = new_size;
	queue = (QUEUE_TYPE *)realloc( queue, ARRAY_SIZE * sizeof( QUEUE_TYPE ) );
	return queue != NULL ? 1 : 0;
}

void destroy_queue( void ) {
	queue_size = 0;
	free( queue );
	queue = NULL;
}
