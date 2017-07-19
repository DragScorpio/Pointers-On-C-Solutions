/* 9.14-1 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main( void ) {
	char *ch, input[128];
	unsigned int cc = 0, wc = 0, dt = 0, ll = 0, ul = 0, pc = 0, nc = 0;
	printf( "%s\n", "please type in any number of chars; type ENTER to exit" );
	fgets( input, 128, stdin );
	for( ch = input; *ch != '\0'; ch++ ) {
		if( iscntrl( *ch ) )
			cc++;
		if( isspace( *ch ) )
			wc++;
		if( isdigit( *ch ) )
			dt++;
		if( islower( *ch ) )
			ll++;
		if( isupper( *ch ) )
			ul++;
		if( ispunct( *ch ) )
			pc++;
		if( !isprint( *ch ) )
			nc++;
	}
	float percentage = (float)wc / (float)strlen( input );
	float percent = percentage * 100;
	printf( "we have %f%% white spaces\n", percent );
	return 0;
}
