/* 5.9-2 */
#include <stdio.h>
#define max_len 128

void encrypt( char str[] );
int main( void ) {
	char str[max_len];
	printf( "%s\n", "please enter a string to be encrypted [Press ENTER to complete...]:" );
	fgets( str, max_len, stdin );
	encrypt( str );
	puts( str );
	return 0;
}

void encrypt( char str[] ) {
	int i = 0;
	char ch;
	while( ( ch = str[i] ) != 0 ) {
		/* ch is neither newline nor the end of string */
		if( ( ch > 64 && ch < 78 ) || ( ch > 96 && ch < 110 ) ) {
			ch += 13;
			str[i] = ch;
		}
		else if( ( ch > 77 && ch < 91 ) || ( ch > 109 && ch < 123 ) ) {
			ch -= 13;
			str[i] = ch;
		}
		i += 1;
	}
}
