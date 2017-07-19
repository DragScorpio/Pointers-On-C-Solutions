/* practice recursion */
#include <stdio.h>
void b2c( unsigned int );
void binary2ascii( unsigned int );
int main( void ) {
	int n;
	printf( "%s", "give me a positive integer please: " );
	scanf( " %u", &n );
	/* b2c( n ); */
	binary2ascii( n );
	return 0;
}
/* my version */
void b2c( unsigned int n ) {
	if( n ) {
		b2c( n/10 );
		putchar( n%10 + '0' );
		n /= 10;
	}
}

/* textbook version */
void
binary2ascii( unsigned int value )
{
	unsigned int quotient;
	quotient = value / 10;
	if( quotient != 0 )
      		binary2ascii( quotient );
	putchar( value % 10 + '0' );
}
