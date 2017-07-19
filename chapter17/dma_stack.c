/* 17.10-1 */
#include "dma_stack.h"

static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

int create_stack( size_t size ) {
	assert( stack == NULL );
	stack_size = size;
	stack = (STACK_TYPE *)calloc( stack_size, sizeof( STACK_TYPE ) );
	return stack != NULL ? 1 : 0;
}

void push( STACK_TYPE value ) {
	assert( !is_full() );
	stack[++top_element] = value;
}

void pop( void ) {
	assert( !is_empty() );
	top_element--;
}

STACK_TYPE top( void ) {
	assert( !is_empty() );
	return stack[top_element];
}

int is_empty( void ) {
	assert( stack_size > 0 );
	return top_element == -1;
}

int is_full( void ) {
	assert( stack_size > 0 );
	return top_element == stack_size - 1;
}

int resize_stack( size_t new_size ) {
	assert( new_size > stack_size );
	stack_size = new_size;
	stack = (STACK_TYPE *)realloc( stack, new_size * sizeof( STACK_TYPE ) );
	return stack != NULL ? 1 : 0;
}

void destroy_stack( void ) {
	stack_size = 0;
	free( stack );
	stack = NULL;
}
