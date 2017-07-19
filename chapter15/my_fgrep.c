/* 15.21-9 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int search_string( FILE *stream, char const *filename, char const *string );
int main( int argc, char **argv ) {
	FILE *input;
	char *string, *filename[10];
	int i;

	string = *++argv;
	if( string == NULL )
		exit( EXIT_FAILURE );

	for( i = 0; *++argv != NULL && i < 10; i++ )
		filename[i] = *argv;

	if( *filename == NULL ) {
		input = stdin;
		filename[1] = "standard input";
	}

	for( i = 0; ( input = fopen( filename[i], "r" ) ) != NULL; i++ ) {
		search_string( input, filename[i], string );
		fclose( input );
	}

	return EXIT_SUCCESS;
}

int search_string( FILE *stream, char const *filename, char const *string ) {
	char line[MAX_LENGTH];
	int count;

	for( count = 0; fgets( line, MAX_LENGTH, stream ) != NULL; count++ )
		if( strstr( line, string ) != NULL )
			printf( "%10s : LINE-%02d : %s", filename, count, line );

	return count;
}
