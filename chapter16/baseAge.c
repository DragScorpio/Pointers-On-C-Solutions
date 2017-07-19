/* 16.14-1 */
#include <stdio.h>

int decimal_to_base( unsigned int age, unsigned int base );
int main( int argc, char **argv ) {
	unsigned int age, fage, base = 1;
	printf( "What is your real age? " );
	scanf( "%u", &age );

	while( base < 36 )
		if( ( fage = decimal_to_base( age, ++base ) ) < 30 )
			break;

	printf( "Your fake age is: %2u; The base is %u\n", fage, base );
	return 0;
}

int decimal_to_base( unsigned int age, unsigned int base ) {
	int i = 1, result = 0;
	while( age ) {
		result += ( age % base ) * i;
		age /= base;
		i *= 10;
	}

	return result;
}
