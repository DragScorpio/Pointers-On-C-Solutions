/* 4.14-6 */
#include <stdio.h>
#include <string.h>

int substr( char dst[], char src[], int start, int len );
int main( void ) {
	char src[128];
	char dst[128];
	int start;
	int len;
	printf( "please enter a string: " );
	fgets( src, 128, stdin );
	printf( "please enter a start number: " );
	scanf( "%d", &start );
	printf( "please enter the length of target: " );
	scanf( "%d", &len );
	printf( "we copied %d chars to the target string.\n", substr( dst, src, start, len ) );
	printf( "the target string is: %s\n", dst );
	return 0;
}

int substr( char dst[], char src[], int start, int len ) {
	if( start < 0 || len < 0 || start >= strlen( src ) ) {
		dst[0] = '\0';
		return 0;
	}
	else {
		int i = 0;
		char *ch = src + start;
		while( ( i < len ) && ( *ch != '\0' ) ) {
			dst[i] = *ch;
			i += 1;
			ch += 1;
		}
		return i - 1;
	}
}
