/* 7.11-2 */
#include <stdio.h>

unsigned int gcd( unsigned int, unsigned int );
int main( void ) {
	printf( "%i\n", gcd(20, 10) );
	printf( "%i\n", gcd(15, 75) );
	printf( "%i\n", gcd(69, 169) );
	printf( "%i\n", gcd(49, 63) );
	printf( "%i\n", gcd(121, 1100) );
	return 0;
}

unsigned int gcd( unsigned int m, unsigned int n ) {
	unsigned int r;
	while( r = m % n ) {
		m = n;
		n = r;
	}
	return n;
}

/*	       ---M%N == 0:        N
**	      |
** gcd(M,N) = |
**	      |
**	       ---M%N == R, R > 0: gcd(N,R)
*/
