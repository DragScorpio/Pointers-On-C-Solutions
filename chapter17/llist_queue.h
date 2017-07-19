/* 17.10-3 */
#ifndef _LLIST_QUEUE
#define _LLIST_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define QUEUE_TYPE int

typedef struct QUEUE {
	QUEUE_TYPE value;
	struct QUEUE *next;
} Queue;

void enqueue( QUEUE_TYPE value );
void dequeue( void );
QUEUE_TYPE first( void );
int is_empty( void );
void destroy_queue( void );

#endif
