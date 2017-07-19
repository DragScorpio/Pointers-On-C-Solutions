/* 9.14-7 */
#include <stdio.h>
char *my_strchr( char const* string, int ch );
int main( void ) {
	char *string = "hello, hello, hellhello!";
	printf( "%s\n", my_strchr( string, 'o' ) );
	return 0;
}

char *my_strchr( char const* string, int ch ) {
	char *ret = NULL;
	while( *string ) {
		if( *string == ch )
			ret = string;

		string++;
	}
	return ret;
}
