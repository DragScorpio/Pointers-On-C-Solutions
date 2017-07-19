/* 15.21-8 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main( int argc, char **argv ) {
	FILE *input, *dump;
	char *filename = *++argv;
	unsigned char hexdump[16], *ch;
	unsigned int i, n;
	long int offset;

	input = fopen( filename, "rb" );
	dump = fopen( "hexdump", "w" );

	if( input == NULL || dump == NULL )
		exit( EXIT_FAILURE );

	for( offset = ftell( input ); fread( hexdump, 16, 1, input ) == 1; offset = ftell( input ) ) {
		fprintf( dump, "%06lX  ", offset );
		for( i = 0; i < 16; i += 4 )
			fprintf( dump, "%02X%02X%02X%02X ", hexdump[i], hexdump[i+1], hexdump[i+2], hexdump[i+3] );

		fprintf( dump, " *" );
		for( i = 0, ch = hexdump; i < 16; i++, ch++ )
			isspace( *ch ) ? fputc( '.', dump ) : fputc( *ch, dump );

		fprintf( dump, "*\n" );
	}

	if( offset != EOF ) { /* i.e., there are less than 16 bytes to be read */
		fprintf( dump, "%06lX ", offset );
		n = ftell( input ) - offset;  /* n is the number of bytes left */
		fseek( input, offset, SEEK_SET );

		for( i = 0; i < n; i++ )
			fprintf( dump, i % 4 ? "%02X" : " %02X", hexdump[i] );

		fprintf( dump, "  *" );
		for( i = 0, ch = hexdump; i < n; i++, ch++ )
                        isspace( *ch ) ? fputc( '.', dump ) : fputc( *ch, dump );

		fprintf( dump, "*\n" );
	}

	fclose( input );
	fclose( dump );

	return EXIT_SUCCESS;
}
