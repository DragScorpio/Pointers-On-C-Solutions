/* 17.10-2 */
#ifndef _DMA_QUEUE_H
#define _DMA_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_TYPE int
int create_queue( size_t size );
void enqueue( QUEUE_TYPE value );
void dequeue( void );
QUEUE_TYPE first( void );
int is_empty( void );
int is_full( void );
void destroy_queue( void );
int resize_queue( size_t new_size );

#endif
