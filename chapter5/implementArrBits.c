/* 5.9-4 */
#include <stdio.h>
#include <string.h>
#define int_size 128

int validate( char bit_array[], int n );
void set_bit( char bit_array[], unsigned int bit_number );
void clear_bit( char bit_array[], unsigned int bit_number );
void assign_bit( char bit_array[], unsigned int bit_number, int value );
int test_bit( char bit_array[], unsigned int bit_number );
int main( void ) {
	char bit_array[int_size], choice, loop = 'y';
	unsigned int bit_number;
	int value;
	/* menu loop */
	while( loop == 'y' ) {
		printf( "%s\n", "please enter a binary number:" );
		scanf( "%s", bit_array );
		/* validate bits value either 0 or 1 */
		int len = strlen( bit_array );
		if( !validate( bit_array, len ) )
			continue;
		/* validate bit_number within integer range: 32bits */
		printf( "%s\n", "please enter the bit_number to be processed:" );
		scanf( "%u", &bit_number );
		while( bit_number > len - 1 )  {
			printf( "%s ", "the bit_number is out of range, please re-enter:" );
			scanf( "%u", &bit_number );
		}
		/* select the right function to call */
		printf( "%s\n", "please tell how do you want to deal with binary number?" );
		int select = 0;
		do {
			printf( "%s\n", "s --- set bit" );
			printf( "%s\n", "c --- clear bit" );
			printf( "%s\n", "a --- assign bit" );
			printf( "%s\n", "t --- test bit" );
			scanf( " %c", &choice );
			switch( choice ) {
			case 's':
			case 'S':
				set_bit( bit_array, bit_number );
				break;
			case 'c':
			case 'C':
				clear_bit( bit_array, bit_number );
				break;
			case 'a':
			case 'A':
				printf( "%s\n", "enter the value to assign:" );
				scanf( "%d", &value );
				assign_bit( bit_array, bit_number, value );
				break;
			case 't':
			case 'T':
				if( test_bit( bit_array, bit_number ) )
					printf( "%s\n", "the bit was set." );
				else
					printf( "%s\n", "the bit wasn't set." );
				break;
			default:
				printf( "%s\n", "invalid choice. please re-enter." );
				select = 1;
			}
		} while( select );
		/* let user choose to continue or not */
		printf( "%s ", "do you want to continue? [y/n]" );
		scanf( " %c", &loop );
		switch( loop ) {
		case 'y':
		case 'Y':
			loop = 'y';
			break;
		case 'n':
		case 'N':
			loop = 'n';
			break;
		default:
			printf( "%s\n", "invoid choice. system default your choice to be y: 'yes'" );
			loop = 'y';
		}
	}
	return 0;
}

int validate( char bit_array[], int n ) {
	char *ch = bit_array;
	while( *ch != 0 ) {
		if( *ch != 48 && *ch != 49 ) {
			printf( "%s\n", "containing error bit(s)..." );
			return 0;
		}
		else
			ch += 1;
	}
	return 1;
}

void set_bit( char bit_array[], unsigned int bit_number ) {
	bit_array[bit_number] = 49;
	printf( "the binary is modified:\t%s\n", bit_array );
}

void clear_bit( char bit_array[], unsigned int bit_number ) {
	bit_array[bit_number] = 48;
	printf( "the binary is modified:\t%s\n", bit_array );
}

void assign_bit( char bit_array[], unsigned int bit_number, int value ) {
	while( value != 0 && value != 1 ) {
		printf( "%s\n", "invalid value! please re-enter:" );
		scanf( "%d", &value );
	}
	bit_array[bit_number] = value + 48;
	printf( "the binary is modified:\t%s\n", bit_array );
}

int test_bit( char bit_array[], unsigned int bit_number ) {
	if( bit_array[bit_number] == 49 )
		return 1;
	else
		return 0;
}
