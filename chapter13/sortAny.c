/* 13.10-4 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort( void *array, size_t num, size_t size, int (*comp_func)( void const *, void const * ) );
int cmp_int( void const*, void const* );
int cmp_char( void const*, void const* );
int cmp_float( void const*, void const* );
int cmp_cstring( void const*, void const* );
void swap_val( void *var1, void *var2, size_t size );

int main( void ) {
	int i;
	char char_arr[20] = { 'a', 'A', 'v', 'r', 'T', 'y', 'U', 'i', 'i', 'o', 'O', 'w', 'Q', 'L', 'h',
			      'b', 'B', 'r', 'e', 'a' };
	int int_arr[20] = { 1, 99, 23, 45, 899, 1000, 3, 9, 87, 10, 11, 19, 1, 45, 23, 87, 99, 43, 21, 0 };
	float float_arr[20] = { 2.99, 10.01, 98.22, 22.34, 44.51, 68.03, 11.02, 99.24, 99.32, 65.35, 2.98, 3.90, 8.00,
				3.23, 7.98, 999.91, 89.04, 45.63, 81.23, 45.03 };
	char *string_arr[20] = { "abce", "A", "hello", "Shwartz", "jerry", "perfume", "zoology", "enter",
				 "kohan", "king", "Geology", "opps", "uganda", "spadus", "hellsing",
				 "naruto", "NATO", "Sunxiangzhen", "xiangzhen", "jesus" };

	sort( char_arr, 20, sizeof( char ), cmp_char );
	sort( int_arr, 20, sizeof( int ), cmp_int );
	sort( float_arr, 20, sizeof( float ), cmp_float );
//	sort( string_arr, 20, sizeof( char * ), cmp_cstring );

/*
	qsort( char_arr, 20, sizeof( char ), cmp_char );
	qsort( int_arr, 20, sizeof( int ), cmp_int );
	qsort( float_arr, 20, sizeof( float ), cmp_float );
	qsort( string_arr, 20, sizeof( char * ), cmp_cstring );
*/
	for( i = 0; i < 19; i++ )
                printf( "%c ", char_arr[i] );
        printf( "%c\n", char_arr[i] );

	for( i = 0; i < 19; i++ )
		printf( "%i ", int_arr[i] );
	printf( "%i\n", int_arr[i] );

	for( i = 0; i < 19; i++ )
                printf( "%f ", float_arr[i] );
        printf( "%f\n", float_arr[i] );

	for( i = 0; i < 20; i++ )
                printf( "%s\n", string_arr[i] );
	return 0;
}

void sort( void *array, size_t num, size_t size, int (*comp_func)( void const *, void const * ) ) {
	int i, j;
	for( i = 0; i < num - 1; i++ ) {
		for( j = i + 1; j < num; j++ ) {
			if( comp_func( array + i, array + j ) > 0 )
				swap_val( array + i, array + j, size );
		}
	}
}

int cmp_int( void const *var1, void const *var2 ) {
	int a = *(int *)var1;  /* we do cast because we cannot do algorithms on *var1 or *var2, which are void type */
	int b = *(int *)var2;
	return ( a > b ) - ( a < b );  /* because unsigned types a, b, making the result a - b always positive */
	/* secondly, memcmp( a, b ) treat a and b both as unsigned char type!!! */
}

int cmp_char( void const *var1, void const *var2 ) {
        char a = *(char *)var1;
        char b = *(char *)var2;
        return ( a > b ) - ( a < b );
}

int cmp_float( void const *var1, void const *var2 ) {
        float a = *(float *)var1;
        float b = *(float *)var2;
        return ( a > b ) - ( a < b );
}

int cmp_cstring( void const *var1, void const *var2 ) {
	char **ptr1 = (char **)var1;
	char **ptr2 = (char **)var2;
	return strcmp( *ptr1, *ptr2 );
}

void swap_val( void *var1, void *var2, size_t size ) {
	char *x = (char *)var1;
	char *y = (char *)var2;  /* cast var1, var2 into an array of size chars */
	char temp[1];  /* temp is a pointer to a single char, with allocated space */
	while( size-- ) {
		memcpy( temp, x, 1 );
		memcpy( x, y, 1 );
		memcpy( y, temp, 1 );
		x += 1;
		y += 1;  /* move to the next byte of array x and y */
	}
}
