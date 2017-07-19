/* 7.11-3 */
#include <stdio.h>
int ascii_to_integer( char* );
int main( void ) {
	char string[128];
	printf( "%s\n", "please enter a string with only numbers" );
	scanf( " %s", string );
	printf( "%i\n", ascii_to_integer( string ) );
	return 0;
}

int ascii_to_integer( char* string ) {
	char ch;
	int result = 0;
	while( ch = *string++ ) {
		if( ch < '0' || ch > '9' )
			return 0;
		result = 10 * result + ch - '0';
	}
	return result;
}
