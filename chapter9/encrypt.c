/* 9.14-13 */
#include <stdio.h>
#include <ctype.h>

void encrypt( char *data, char const *key );
int main( void ) {
	char data[128];
	char coded_key[30] = "TRAILBZESCDFGHJKMNOPQUVWXY";
	printf( "%s\n", "Enter the message to be encoded here:" );
	fgets( data, 128, stdin );
	encrypt( data, coded_key );
	printf( "\nYour message was encoded to:\n%s", data );

	return 0;
}

void encrypt( char *data, char const *key ) {
	int idx;
	while( *data ) {
		if( isalpha( *data ) ) {
			idx = toupper( *data ) - 'A';
			*data = key[idx];
		}

		data++;
	}
}
