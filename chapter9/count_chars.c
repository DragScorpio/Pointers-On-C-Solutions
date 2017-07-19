/* 9.14-9 */
#include <stdio.h>
int count_chars( char const *str, char const *chars );
int main( void ) {
	char *str = "hello, world, I am\tXiangzhen Sun,\vGreetings here!\n";
	printf( "%s", str );
	printf( "%i", count_chars( str, "\n\t\v ," ) );
	return 0;
}

int count_chars( char const *str, char const *chars ) {
	char const *ch;
	int count = 0;
	while( *str ) {
		for( ch = chars; *ch; )
			if( *ch++ == *str )
				count++;
		str++;
	}
	return count;
}
