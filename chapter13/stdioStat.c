/* 13.10-1 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int (*char_type[])( int ch );
int isnonprint( int ch );
int main( void ) {
	char ch;
	double stat[7];
	int i, j, sum, len = 0, size = 20;

	char *str = (char *)malloc( size );
	if( str == NULL )
		exit( EXIT_FAILURE );

	while( ( ch = getchar() ) != EOF ) {
		if( len >= size ) {
			size += 20;
			str = (char *)realloc( str, size );
		}

		if( str == NULL )
			break;

		*( str + len++ ) = ch;
	}
	*( str + len++ ) = EOF;  /* the last char must be EOF */

	for( i = 0; i < 7; i++ ) {
		for( sum = 0, j = 0; j < len; j++ )
			sum += char_type[i]( str[j] ) ? 1 : 0;

		stat[i] = sum * 100.00 / len;
	}
	free( str );

	for( i = 0; i < 7; i++ )
		printf( "%f percent\n", stat[i] );

	return 0;
}

int (*char_type[])( int ch ) = { iscntrl, isspace, isdigit, islower, isupper, ispunct, isnonprint };
int isnonprint( int ch ) {
	return !isprint( ch );
}
