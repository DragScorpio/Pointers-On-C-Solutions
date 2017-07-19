/* 5.9-3 */
#include <stdio.h>

unsigned int reverse_bits( unsigned int value );
int main( void ) {
	unsigned int value;
	printf( "%s\n", "please enter an unsigned number:" );
	scanf( "%d", &value );
	printf( "\nthe bitwise-reversed number in decimal:\t%u\n", reverse_bits( value ) );
	return 0;
}

unsigned int reverse_bits( unsigned int value ) {
	unsigned int init = 1;
	int isize = 0;
	while( init ) {
		init <<= 1;
		isize += 1;
	}
	/* this loop test the integer size of this machine */
	printf( "****this machine has integer size of %d bits****\n", isize );

	unsigned int result, bitNum[isize], i = 0;
	/* bitNum[] stores the bit number of each digits in reversed order */
	while( i < isize ) {
		bitNum[i] = ( value & ( 1 << i ) ) >> i;
		result += bitNum[i] << ( isize - i - 1 );
		i += 1;
	}

	/* test result in binary format */
	printf( "%s\t", "the bitwise-reviersed number in binary:" );
	while( i ) {
		printf( "%u", bitNum[isize - i] );
		i -= 1;
	}

	return result;
}
