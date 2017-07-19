/* 17.10-1 */
#ifndef _DMA_STACK_H
#define _DMA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define STACK_TYPE int

int create_stack( size_t size );
void push( STACK_TYPE value );
void pop( void );
STACK_TYPE top( void );
int is_empty( void );
int is_full( void );
int resize_stack( size_t new_size );
void destroy_stack( void );

#endif
