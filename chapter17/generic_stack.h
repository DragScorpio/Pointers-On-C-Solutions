/* 17.10 -11 */
#ifndef _GENERIC_STACK
#define _GENERIC_STACK

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* declare generic interface for stack */
#define DECLARE_GENERIC_STACK( TYPE )				\
	typedef struct STACK_##TYPE {				\
		TYPE key;					\
		struct STACK_##TYPE *next;			\
	} Stack_##TYPE;						\
								\
	int is_empty_##TYPE( Stack_##TYPE *s );			\
	void push_##TYPE( TYPE key, Stack_##TYPE **s);		\
	void pop_##TYPE( Stack_##TYPE **s );			\
	TYPE top_##TYPE( Stack_##TYPE *s );


/* define generic functions for stack */
#define DEFINE_GENERIC_STACK( TYPE )						\
	int is_empty_##TYPE( Stack_##TYPE *s ) {				\
		return s == NULL;						\
	}									\
										\
	void push_##TYPE( TYPE key, Stack_##TYPE **s) {				\
		Stack_##TYPE *new_node;						\
		new_node = (Stack_##TYPE *)malloc( sizeof(Stack_##TYPE) );	\
		assert( new_node != NULL );					\
										\
		new_node->key = key;						\
		new_node->next = *s;						\
		*s = new_node;							\
	}									\
										\
	void pop_##TYPE( Stack_##TYPE **s ) {					\
		Stack_##TYPE *first = *s;					\
										\
		assert( !is_empty_##TYPE( first ) );				\
		*s = first->next;						\
		free( first );							\
		first = NULL;							\
	}									\
										\
	TYPE top_##TYPE( Stack_##TYPE *s ) {					\
		assert( !is_empty_##TYPE( s ) );				\
		return s->key;							\
	}


/* create data */
#define GENERIC_STACK( TYPE )	Stack_##TYPE

#endif
