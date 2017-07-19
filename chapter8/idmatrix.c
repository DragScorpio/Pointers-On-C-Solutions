/* 8.8-4 */
#include <stdio.h>
int identity_matrix( int const* array, int size );
int main( void ) {
	int array1[25] = {1,0,0,0,0,
			  0,1,0,0,0,
			  0,0,1,0,0,
			  0,0,0,1,0,
			  0,0,0,0,1};
	int array2[16] = {1,0,0,0,
			  0,1,0,0,
			  0,0,1,1,
			  0,0,0,1};
	int array3[25] = {1,0,0,0,0,
			  0,1,0,0,0,
			  0,0,1,0,0,
			  0,0,0,1,0,
			  0,0,0,0,2};
	int array4[9] = {1,0,0,
			 0,1,0,
			 0,0,1};

	printf( "---%i\n", identity_matrix( array1, 5 ) );
	printf( "---%i\n", identity_matrix( array2, 4 ) );
	printf( "---%i\n", identity_matrix( array3, 5 ) );
	printf( "---%i\n", identity_matrix( array4, 3 ) );
	return 0;
}

int identity_matrix( int const* array, int size ) {
	int i, j;
	int const *element;
	for( i = -1, element = array - 1; ++element - array < size * size && ++i < size * size; )
	{
		j = i / size;
		if( element - array == size * j + j ) {
			if( *element != 1 )
				return 0;
		}
		else {
			if( *element )
				return 0;
		}
	/* test case:
		printf( "%i ", *element ); */
	}
	return 1;
}
