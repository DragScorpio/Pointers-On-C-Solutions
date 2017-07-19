/* 11.11-2 */
#include <stdio.h>
#include <stdlib.h>

int* read_from_stdin( int *num );
int main( void ) {
	int i, *num, *array;
	array = read_from_stdin( num );

	for( i = 0; i < *num; i++ )
		printf( "%d\n", *( array + i ) );

	free( array );
	return 0;
}

int* read_from_stdin( int *num ) {
	int *array;
	int i = 0;

	scanf( "%d", num );
	array = calloc( *num, sizeof( int ) );

	if( array != NULL )
		while( scanf( "%d", array + i++ ) != EOF && i < *num );

	return array;
}
