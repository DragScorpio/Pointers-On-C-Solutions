/* 9.14-14 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decrypt( char *data, char const *key );
int main( void ) {
	char data[128];
	char coded_key[30] = "TRAILBZESCDFGHJKMNOPQUVWXY";
	printf( "%s\n", "Enter the coded message here:" );
	fgets( data, 128, stdin );
	decrypt( data, coded_key );
	printf( "\nYour message was translated to:\n%s", data );

	return 0;
}

void decrypt( char *data, char const *key ) {
	int ch;
	 while( *data ) {
		if( isalpha( *data ) ) {
			ch = strchr( key, *data ) - key;
			*data = ch + 'A';
		}

		data++;
	}
}
