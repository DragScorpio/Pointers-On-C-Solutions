/* 15.21-4 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LEN 100

int main( void ) {
	FILE *input, *output;
	char read_file[80], write_file[80], line[MAX_LINE_LEN];

	printf( "Please enter the filename to be read from: " );
	scanf( "%s", read_file );
	printf( "Please enter the filename to be written to: " );
	scanf( "%s", write_file );

	input = fopen( read_file, "r" );
	output = fopen( write_file, "w" );

	if( input == NULL || output == NULL ) {
		perror( "input/output" );
		exit( EXIT_FAILURE );
	}

	while( fgets( line, MAX_LINE_LEN, input ) != NULL )
		fputs( line, output );

	fclose( input );
	fclose( output );
	return EXIT_SUCCESS;
}
