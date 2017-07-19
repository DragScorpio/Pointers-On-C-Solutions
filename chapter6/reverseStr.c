/* 6.18-3 */
#include <stdio.h>

void reverse_string( char *string );
void swap_char( char *a, char *b );
int main( void ) {
	/* test cases */
	char string[128] = "A B C d e f g h I j k L M N\t";
	char string1[128] = "";
	char string2[128] = "B";
	reverse_string( string );
	reverse_string( string1 );
	reverse_string( string2 );
	printf( "%s\n", string );
	printf( "%s\n", string1 );
	printf( "%s\n", string2 );
	return 0;
}

void reverse_string( char *string ) {
/* reverse the sequence of string chars */
	int length = 0;
	char *sptr = string;
	while( *sptr != 0 ) {
		sptr++;
		length++;
	}

	int loop = length / 2;
	while( loop-- )
		swap_char( string++, --sptr );
}

void swap_char( char *a, char *b ) {
/* swapping the position of two chars */
	char ch = *a;
	*a = *b;
	*b = ch;
}
