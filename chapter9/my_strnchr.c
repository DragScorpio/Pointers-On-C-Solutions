/* 9.14-8 */
#include <stdio.h>

char *my_strnchr( char const *str, int ch, int which );
int main( void ) {
	char *str = "hello, hello, hello, hello, world!";
	printf( "%s\n", my_strnchr( str, 'h', 0 ) );
	printf( "%s\n", my_strnchr( str, 'h', 1 ) );
	printf( "%s\n", my_strnchr( str, 'h', 2 ) );
	printf( "%s\n", my_strnchr( str, 'h', 3 ) );
	printf( "%s\n", my_strnchr( str, 'h', 4 ) );
	printf( "%s\n", my_strnchr( str, 'h', 5 ) );
	return 0;
}

char *my_strnchr( char const *str, int ch, int which ) {
	if( which < 1 )
		return NULL;

	while( *str && which ) {
		if( *str++ == ch )
			which--;
	}

	if( which )
		return NULL;
	else
		return str - 1;
}
