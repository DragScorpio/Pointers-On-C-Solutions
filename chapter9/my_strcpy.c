/* 9.14-3 */
#include <stdio.h>
#include <string.h>
char *my_strcpy( char *dst, char const* src );
int main( void ) {
	char dst[15] = "hello, world!";  // 14 bytes
	char src[23] = "Xiangzhen Sun is King";  // 22 bytes
//	printf( "%s\n", my_strcpy( dst, src ) );

	return 0;
}

char *my_strcpy( char *dst, char const* src ) {
	char *copy = dst;
	int size = strlen( dst );
	printf( "%i\n", size );
	while( ( *dst++ = *src++ ) && --size );

	if( !size )
		*dst = 0;

//	printf( "%i\n", size );
	return copy;
}
