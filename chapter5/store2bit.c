/* 5.9-5 */
#include <stdio.h>

int store_bit_field( int original_value, int value_to_store, unsigned int starting_bit, unsigned int ending_bit );
int main( void ) {
	int original_value, value_to_store;
	unsigned int starting_bit, ending_bit;
	printf( "%s\n", "please enter the original value:" );
	scanf( "%i", &original_value );
	printf( "%s\n", "please enter the value to store:" );
	scanf( "%i", &value_to_store );
	printf( "%s\n", "please enter the starting bit:" );
	scanf( "%u", &starting_bit );
	printf( "%s\n", "please enter the ending_bit:" );
	scanf( "%u", &ending_bit );
	if( starting_bit >= ending_bit && starting_bit < 32 && ending_bit < 32 ) {
		printf( "%s\n", "the converted value is:" );
		printf( "%d\n", store_bit_field( original_value, value_to_store, starting_bit, ending_bit ) );
	}
	else
		printf( "%s\n", "error bit number, exiting program..." );
	return 0;
}

int store_bit_field( int original_value, int value_to_store, unsigned int starting_bit, unsigned int ending_bit ) {
	/* create a musk */
	unsigned int oValue = ( unsigned int )original_value;
	unsigned int nValue = ( unsigned int )value_to_store;
	/* after casting, new values have bits numbered 0 - 31 */
	unsigned int mask = 1;
	unsigned int i = starting_bit - ending_bit;
	while( i ) {
		mask += ( 1 << i );
		i -= 1;
	}
	mask <<= ending_bit;
	/* mask is now a value with ones only in the bit positions in the desired field */

	unsigned int cValue = oValue & ( ~mask );
	/* using one's complement of mask to clear all bits in the field */

	/* Shift the new value left so that it is aligned in the field */
	nValue <<= ending_bit;

	/* AND the shifted value with the mask to ensure that it has no bits outside of the field */
	nValue &= mask;

	/* OR the resulting value into the original integer */
	return (int)( cValue | nValue );
}
