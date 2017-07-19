/*
**this is a generic swap function
** it can swap a pair of any type of data
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void byte_swap( void *ptr1, void *ptr2, size_t size );
int main( void ) {
	char *ch1, *ch2;
	int *i1, *i2;
	float *f1, *f2;

	char a1 = 'a', a2 = 'b';
	int b1 = -1, b2 = -2;
	float c1 = 1.23, c2 = -2.04;

	ch1 = &a1;
	ch2 = &a2;
	i1 = &b1;
	i2 = &b2;
	f1 = &c1;
	f2 = &c2;

	byte_swap( ch1, ch2, sizeof( char ) );
	byte_swap( i1, i2, sizeof( int ) );
	byte_swap( f1, f2, sizeof( float ) );

	printf( "%c, %c\n", *ch1, *ch2 );
	printf( "%i, %i\n", *i1, *i2 );
	printf( "%f, %f\n", *f1, *f2 );

	return 0;
}

void byte_swap( void *ptr1, void *ptr2, size_t size ) {
	unsigned char *temp = ( unsigned char * )malloc( size );
        memmove( temp, ptr1, size );
        memmove( ptr1, ptr2, size );
        memmove( ptr2, temp, size );
	free( temp );
}
