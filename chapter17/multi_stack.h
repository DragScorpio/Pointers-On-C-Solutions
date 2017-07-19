/* 17.10-4 */
#ifndef _MULTI_STACK_H
#define _MULTI_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define STACK_TYPE int

int create_stack( size_t size, int index );

/* push value to the stack marked by index */
void push( STACK_TYPE value, int index );

void pop( int index );
STACK_TYPE top( int index );
int is_empty( int index );
int is_full( int index );
int resize_stack( size_t new_size, int index );
void destroy_stack( int index );

#endif
