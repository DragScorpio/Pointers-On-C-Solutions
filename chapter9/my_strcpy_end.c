/* 9.14-6 */
#include <stdio.h>
char *my_strcpy_end( char *dst, char const* src );
int main( void )  {
	char dst[10] = "here's A";
	char src[10] = "here is B";
	if( !*my_strcpy_end( dst, src ) )
		printf( "%s\n", dst );

	return 0;
}

char *my_strcpy_end( char *dst, char const* src ) {
	while( *dst++ = *src++ );
	return --dst;
}
