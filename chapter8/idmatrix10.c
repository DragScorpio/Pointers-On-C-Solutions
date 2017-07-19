/* 8.8-3 */
#include <stdio.h>
int identity_matrix( int matrix[10][10] );
int main( void ) {
	int matrix1[][10] = { {1}, {0,1}, {0,0,1}, {0,0,0,1}, {0,0,0,0,1},
			{0,0,0,0,0,1}, {0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,1},
			{0,0,0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,0,0,1} };
	int matrix2[][10] = { {0, 1}, {1, 0}, {3, 1, 0, 0}, {0, 2}, {2, 4},
			{0}, {0}, {0}, {0}, {0} };
	printf( "%d\n", identity_matrix( matrix1 ) );
	printf( "%d\n", identity_matrix( matrix2 ) );
	return 0;
}

int identity_matrix( int matrix[10][10] ) {
	int i, j;
	for( i = 0; i < 10; i++ ) {
		j = 0;
		while( j < 10 ) {
			if( i == j && matrix[i][j] != 1 )
				return 0;
			else if( i != j && matrix[i][j] != 0 )
				return 0;
			else
				j++;
		}
	}
	return 1;
}
