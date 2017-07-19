/* 16.14-10 */
/*
**I proudly present you the
** Generic Insertion Sort
** all types of data except for structures, can be sorted
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort( void *basePtr, size_t num, size_t size, int (*compare)( void const *, void const * ) );
int compar_ch( void const *a, void const *b );
int compar_int( void const *a, void const *b );
int compar_float( void const *a, void const *b );
int compar_string( void const *a, void const *b );
void byte_swap( void *ptr1, void *ptr2, size_t size );

int main( void ) {
	int i;
	char char_arr[20] = { 'f', 'g', 't', 'A', 'r', 'R', 'a', 'z', 'y', 'g',
			      'w', 'e', 'E', 'H', 'j', 'K', 'l', 'Q', 'X', 'B' };

	int int_arr[20] = { -1, 20, 13, 4, 7, 89, 12, -10, 1, -10, 11, 23, 42, 11, 9, 3, 2, 64, 22, 0 };

	float float_arr[20] = { -1.23, 2.46, 5.97, 8.23, 6.11, 2.22, 13.23, 23.11, 49.00, 11.11,
				2.33, 12.23, 5.43, 2.34, 5.66, 8.99, 8.17, 0.00, -2.19, -9.18 };

	char *string[20] = { "Abe", "cry", "cynic", "greet", "Alexandar", "dodo", "beach", "Y", "hey", "glum",
			"beast", "feast", "Yam", "tomato", "Mom", "Father", "crisis", "pop", "T-bone", "ray" };

	insertion_sort( char_arr, 20, sizeof( char ), compar_ch );
	insertion_sort( int_arr, 20, sizeof( int ), compar_int );
	insertion_sort( float_arr, 20, sizeof( float ), compar_float );
	insertion_sort( string, 20, sizeof( char **), compar_string );

	for( i = 0; i < 20; i++ )
		printf( "%c  ", char_arr[i] );

	printf( "\n" );
	for( i = 0; i < 20; i++ )
		printf( "%i  ", int_arr[i] );

	printf( "\n" );
	for( i = 0; i < 20; i++ )
		printf( "%.2f  ", float_arr[i] );

	printf( "\n" );
	for( i = 0; i < 20; i++ )
		printf( "%s\n", string[i] );

	return 0;
}

void insertion_sort( void *basePtr, size_t num, size_t size, int (*compar)( void const *, void const * ) ) {
	int i, j;
	unsigned char *key = ( unsigned char * )malloc( size );
	unsigned char *arr = ( unsigned char * )basePtr;
	if( key == NULL )
		exit( EXIT_FAILURE );

	for( j = 1; j < num; j++ ) {
		memmove( key, arr + j * size, size );
		i = j - 1;
		while( i > -1 && compar( arr + i * size, key ) > 0 ) {
			memmove( arr + ( i + 1 ) * size, arr + i * size, size );
			i = i - 1;
		}
		memmove( arr + ( i + 1 ) * size, key, size );
	}
}

int compar_ch( void const *a, void const *b ) {
	return *(char *)a - *(char *)b;
}

int compar_int( void const *a, void const *b ) {
	return *(int *)a - *(int *)b;
}

int compar_float( void const *a, void const *b ) {
	return ( *(float *)a > *(float *)b ) - ( *(float *)a < *(float *)b );
}

int compar_string( void const *a, void const *b ) {
	return strcmp( *(char **)a, *(char **)b );
}

void byte_swap( void *ptr1, void *ptr2, size_t size ) {
	unsigned char *temp = ( unsigned char * )malloc( size );
	memmove( temp, ptr1, size );
	memmove( ptr1, ptr2, size );
	memmove( ptr2, temp, size );
	free( temp );
}
