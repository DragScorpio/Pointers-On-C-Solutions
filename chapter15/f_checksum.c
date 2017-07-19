/* 15.21-10 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int checksum( FILE *stream );
int main( int argc, char **argv ) {
	FILE *file;
	char *inputfile, *outputfile;
	unsigned int sum;

	if( *++argv != NULL && strcmp( *argv, "-f" ) == 0 ) {
	/* print checksum to designated file; input file(s) needed */

		if( argc == 2 ) { /* "sum -f" is illegal cmd */
			printf( "-f illegal when reading standard input\n" );
			exit( EXIT_FAILURE );
		}

		while( ( inputfile = *++argv ) != NULL ) {

			file = fopen( inputfile, "r" );
			if( file == NULL ) {
				perror( inputfile );
				exit( EXIT_FAILURE );
			}

			sum = checksum( file );
			outputfile = (char *)malloc( strlen( inputfile ) + 5 );
			strcpy( outputfile, inputfile );
			strcat( outputfile, ".cks" );  /* create output file name */

			file = freopen( outputfile, "w", file );
			if( file == NULL ) {
                                perror( outputfile );
                                exit( EXIT_FAILURE );
                        }

			fprintf( file, "%u", sum );
			fclose( file );
			free( outputfile );
		}
	}
	else if( *argv == NULL ) /* print checksum to stdout; read from stdin */
		printf( "%u\n", checksum( stdin ) );
	else {
		do{
			inputfile = *argv++;
			file = fopen( inputfile, "r" );

			if( file == NULL ) {
                        	perror( inputfile );
                                exit( EXIT_FAILURE );
                        }

			printf( "%s: checksum = %u\n", inputfile, checksum( file ) );
			fclose( file );
		} while( *argv != NULL );
	}

	return EXIT_SUCCESS;
}

unsigned int checksum( FILE *stream ) {
	unsigned int ch, sum;
	for( sum = 0; ( ch = fgetc( stream ) ) != EOF; sum += ch );

	return sum;
}
