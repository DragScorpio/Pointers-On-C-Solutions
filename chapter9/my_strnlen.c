/* 9.14-2 */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t my_strnlen( char const* string, int size );
int main( void ) {
	char dst[15] = "hello, world";
	char src[25] = "don't even piss me!";
	strncpy( dst, src, 15 );
	printf( "the string length is: %i\n", (int)my_strnlen( dst, 15 ) );
	return 0;
}

size_t my_strnlen( char const* string, int size ) {
	int len = 0;
	while( *string++ && size-- )
		len++;

	return len;
}
