/* 11.11-1 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* allocate num memory blocks each occupying size bytes */
void *my_calloc( size_t num, size_t size );

/* reallocate the memory block that is pointed to from ptr, to size bytes instead */
void *my_realloc( void *ptr, size_t old_size, size_t new_size );

int main( void ) {
	int i;
	char *str;
	char string1[20] = "hello, Xiangzhen";
	char string2[30] = "hello, Xiangzhen Sun, loving C";
	str = my_calloc( 20, 1 );

	for( i = 0; i < 20; i++ )
		*( str + i ) = string2[i];

	printf( "%s\n", str );

	str = my_realloc( str, 20, 30 );
	printf( "%s\n", str );

	for( i = 0; i < 30; i++ )
		*( str + i ) = string2[i];

	printf( "%s\n", str );

	free( str );
	return 0;
}

void *my_calloc( size_t num, size_t size ) {
	void *ptr = malloc( num * size );
	return ptr == NULL ? NULL : ptr;
}

void *my_realloc( void *ptr, size_t old_size, size_t new_size ) {
	void *new_ptr;

	new_ptr = malloc( new_size );
	if( new_ptr != NULL ) {
		new_size < old_size ? memcpy( new_ptr, ptr, new_size ) : memcpy( new_ptr, ptr, old_size );
		free( ptr );
		return new_ptr;
	}
	else
		return NULL;
}
