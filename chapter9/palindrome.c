/* 9.14-10 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome( char const *string );
int main( void ) {
	char *string = " A!\tb..? c\n\nD g' { d cB\t\t\na}";
	char *string1 = "A,CF,de,gE,d,f,,c,a,";
	printf( "%s\n", string );
	printf( "%i\n", palindrome( string ) );
	printf( "%s\n", string1 );
        printf( "%i\n", palindrome( string1 ) );

	return 0;
}

int palindrome( char const *string ) {
	char const *start = string;
	char const *end = string + strlen( string );
	while( start < end ) {
		/* find the next alphabetic char from forward */
		while( !isalpha( *start ) )
			start++;

		/* find the next alphabetic char from backward */
		while( !isalpha( *end ) )
			end--;

		if( tolower( *start++ ) != tolower( *end-- ) )
			return 0;
	}
	return 1;
}
