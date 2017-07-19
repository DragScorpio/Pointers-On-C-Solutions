/* 15.21-6 */
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 10

int numeric_parlindrome( int value );
int main( void ) {
	int num[10] = {101, 203123, 3456543, 14741, 245,
			767, 899012, 1234321, 909, 45};
	int i = -1;

	while( ++i < 10 )
		if( numeric_parlindrome( num[i] ) )
			printf( "Found a parlindrome number: %i\n", num[i] );

	return 0;
}

int numeric_parlindrome( int value ) {
	char buffer[MAX_LENGTH], *str = buffer;
	int val = value;

	while( val && sprintf( str++, "%i", val % 10 ) )
		val /= 10;

	sscanf( buffer, "%i", &val );
	return ( val == value ? 1 : 0 );
}
