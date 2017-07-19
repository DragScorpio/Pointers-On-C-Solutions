/* 5.9-1 */
#include <stdio.h>
#define strlength 128

int main( void ) {
	int i = 0;
	char ch, str[strlength];
	printf( "%s\n", "please enter from here [press ENTER to complete]:" );
	fgets( str, strlength, stdin );

	while( ( ch = str[i] ) != 0 ) {
		if( ch > 64 && ch < 91 )
			str[i] += 32;
		i += 1;
	}
	puts( str );
}
