/* 9.14-11 */
#include <stdio.h>
#include <ctype.h>

int countKW( char const *string, char const *kword );
int main( void ) {
	char string[100];
	char kword[50];
	printf( "%s", "please enter a string: " );
	fgets( string, 100, stdin );
	printf( "%s", "please enter a keyword: " );
	scanf( " %s", kword );
	printf( "the keyword \"%s\" occurs %i times\n", kword, countKW( string, kword ) );
	return 0;
}

int countKW( char const *string, char const *kword ) {
/* assumption: words are separated by one or more whitespaces */
	char const *kw;
	int count = 0;
	while( *string ) {
		/* skip any prefix whitespaces */
		if( isspace( *string ) )
			string++;

		/* start matching test */
		for( kw = kword; *kw == *string && *kw; kw++, string++ );

		/* if matches, count+1; else, skip the unmatched word */
		if( *kw == '\0' && isspace( *string ) )
			count++;
		else
			while( *string && !isspace( *string ) )
				string++;
	}
	return count;
}
