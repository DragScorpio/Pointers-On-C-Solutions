/* 11.11-3 */
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 20

char* read_from_stdin( char *string );
int main( void ) {
	char *string;
	string = read_from_stdin( string );
	printf( "%s\n", string );

	free( string );
	return 0;
}

char* read_from_stdin( char *string ) {
	int i, size = INIT_SIZE;
	string = malloc( size );

	if( string != NULL ) {
		for( i = 0; ( string[i] = getchar() ) != EOF; i++ ) {
			if( i > size - 2 ) {
				size += INIT_SIZE;
				string = realloc( string, size );

				if( string == NULL ) {
					printf( "Error reallocating memory..." );
					return NULL;
				}
			}
		}

		string[i] = '\0';
		if( i  < size - 1 )
			string = realloc( string, i + 1 );
	}

	return string;
}
