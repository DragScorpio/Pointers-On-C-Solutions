#include <stdio.h>
#include <string.h>
#include <ctype.h>
int prepare_key( char *key );
int main( void ) {
	char key[30];
	printf( "%s\n", "What's the keyword?" );
	scanf( " %s", key );

	if( prepare_key( key ) )
		printf( "%s\n", key );
	else
		printf( "%s\n", "Error keyword!" );

	return 0;
}

int prepare_key( char *key ) {
	/* assume that key is at least 27-bits long */
	char letter, *karg, *kw = key;
	char coded_kw[27] = "";  /* A - Z: 65 - 90 */

	/* return false if empty key or containing nonalphetic char */
	do {
		if( isalpha( *kw ) )
			*kw = toupper( *kw );
		else
			return 0;
	} while( *++kw );

	for( kw = coded_kw, karg = key; *karg; karg++ ) {
	/* if next char of key is not in coded_kw, copy it to coded_kw */
		if( strchr( coded_kw, *karg ) == NULL )
			*kw++ = *karg;
	}

	/* copy the rest alphabets into coded_kw */
	for( letter = 'A'; letter <= 'Z'; letter++ ) {
		if( strchr( coded_kw, letter ) == NULL )
			*kw++ = letter;
	}

	*kw = '\0';  /* end of string */
	strcpy( key, coded_kw );

	return 1;
}
