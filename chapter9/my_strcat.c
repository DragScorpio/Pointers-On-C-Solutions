/* 9.14-4 */
#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE( a ) ( sizeof( a ) / sizeof( a[0] ) )
char *my_strcat( char *dst, char const* src, int len );
int main( void ) {
	char str1[20] = "hello, world!";  // 13 chars
	char str2[20] = " Xiangzhen Sun!";  // 15 chars
	int len = ARRAY_SIZE( str1 );
	printf( "%s\n", my_strcat( str1, str2, len ) );
	return 0;
}

char *my_strcat( char *dst, char const* src, int len ) {
	char *ret = dst;
	for( ; *dst; dst++, len-- );

	for( ;len && ( *dst = *src ); len--, dst++, src++ );

	if( !len )
		*( dst - 1 ) = 0;

	return ret;
}
