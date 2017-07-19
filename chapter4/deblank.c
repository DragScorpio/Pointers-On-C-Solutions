/* 4.14-7 */
#include <stdio.h>
#include <string.h>

void deblank( char string[] );
int main( void ) {
	char string[128] = "h  e\nllo,   wor\n\n\nld  , !  t his\n  is \n\tXian\tgzhen\t\t\t Su\t\n n !\n";
	deblank( string );
	printf("%s", string );
	return 0;
}

void deblank( char string[] ) {
/* this function replace all consecutive whitespaces with one space char */
	int len = strlen( string ), i = 0, j = 0;
	char str[len]; /* stores deblanked string */

	while( string[j] != '\0' ) {
		if( ( string[j] == ' ' ) || ( string[j] == '\t' ) || ( string[j] == '\n' ) ) {
			str[i] = ' ';
			i += 1;
			j += 1;
			while( ( string[j] == ' ' ) || ( string[j] == '\t' ) || ( string[j] == '\n' ) )
				j += 1;
				/* at the end of this loop, string[j] is non-whitespace */
		}
		else {
		/* skip the following non-whitespace char and keep looking for the next whitespace */
			str[i] = string[j];
			i += 1;
			j += 1;
		}
	}
	str[i] = '\0';
	strcpy( string, str );
}
