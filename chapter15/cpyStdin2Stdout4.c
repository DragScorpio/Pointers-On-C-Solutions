/* 15.21-5 */
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
	FILE *input, *output;
	char read_file[80], write_file[80];
	int ch, num, sum = 0;

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

	if( fscanf( input, "%d", &num ) == 1 )
		fprintf( output, "%d", num );

	while( ( ch = fgetc( input ) ) != EOF ) {
		fputc( ch, output );
		if( ch == 10 && fscanf( input, "%d", &num ) == 1 ) {
			sum += num;
			fprintf( output, "%d", num );
		}
	}
	fprintf( output, "the total is: %d", sum );

	fclose( input );
	fclose( output );
	return EXIT_SUCCESS;
}
