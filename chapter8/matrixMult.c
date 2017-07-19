/* 8.8-5 */
#include <stdio.h>
void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z );
int main( void ) {
/*
	int A[3][2] = { { 2,-6},
			{ 3, 5},
			{ 1,-1} };
	int B[2][4] = { { 4,-2,-4,-5},
			{-7,-3, 6, 7} };
	int C[3][4];
*/
	int C[12], A[6] = {2,-6,3,5,1,-1}, B[8] = {4,-2,-4,-5,-7,-3,6,7};
	matrix_multiply( A, B, C, 3, 2, 4 );
	int i = -1;
	while( ++i < 12 )
		printf( "%i ", C[i] );

	return 0;
}

void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z ) {
/* note: the matrices are firstly flattened then passed into the function */
/* matrice --> rows : columns; m1 --> x : y; m2 --> y : z; r --> x : z */
	int sum, *cm1, *cm2, *row, *column;
	for( row = m1; row - m1 < x * y; row += y ) {
		for( column = m2; column - m2 < z; column++, *r++ = sum ) {
			for( cm1 = row, cm2 = column, sum = 0; cm1 - row < y; cm2 += z )
				sum += *cm1++ * *cm2;
		}
	}
}
