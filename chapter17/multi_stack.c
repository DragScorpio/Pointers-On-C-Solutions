/* 17.10-4 */
#include "multi_stack.h"
#define N_STACKS 10
static STACK_TYPE *stack[N_STACKS];
static size_t stack_size[N_STACKS];
static int top_element[N_STACKS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int create_stack( size_t size, int index ) {
	assert( stack[index] == NULL );
	stack_size[index] = size;
	stack[index] = (STACK_TYPE *)calloc( stack_size[index], sizeof( STACK_TYPE ) );
	return stack[index] != NULL ? 1 : 0;
}

void push( STACK_TYPE value, int index ) {
	assert( !is_full( index ) );
	top_element[index] += 1;
	stack[index][top_element[index]] = value;
}

void pop( int index ) {
	assert( !is_empty( index ) );
	top_element[index] -= 1;
}

STACK_TYPE top( int index ) {
	assert( !is_empty( index ) );
	return stack[index][top_element[index]];
}

int is_empty( int index ) {
	assert( stack_size[index] > 0 );
	return top_element[index] == -1;
}

int is_full( int index ) {
	assert( stack_size[index] > 0 );
	return top_element[index] == stack_size[index] - 1;
}

int resize_stack( size_t new_size, int index ) {
	assert( new_size > stack_size[index] );
	stack_size[index] = new_size;
	stack[index] = (STACK_TYPE *)realloc( stack[index], new_size * sizeof( STACK_TYPE ) );
	return stack[index] != NULL ? 1 : 0;
}

void destroy_stack( int index ) {
	stack_size[index] = 0;
	free( stack[index] );
	stack[index] = NULL;
}
