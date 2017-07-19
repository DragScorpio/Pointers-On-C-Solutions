/* 7.11-1 */
#include <stdio.h>
int hermite( int, int );
int main( void ) {
	printf( "%d\n", hermite( -3, 10 ) );
	printf( "%d\n", hermite( 1, 17 ) );
	printf( "%d\n", hermite( 3, 2 ) );
	printf( "%d\n", hermite( 7, 5 ) );
	return 0;
}

int hermite( int n, int x ) {
	if( n <= 0 )
		return 1;
	else if( n == 1 )
		return 2 * x;
	else {
		int Hn = 2 * x * hermite( n - 1, x ) - 2 * ( n - 1 ) * hermite( n - 2, x );
		return Hn;
	}
}
