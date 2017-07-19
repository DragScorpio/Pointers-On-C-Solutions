/* 15.21-3 */
#include <stdio.h>

int main( void ) {
	char line[2];   /* read piece by piece: 2 is the minimum length of string that can be
			** processed by fgets();
			*/
	while( fgets( line, 2, stdin ) )
		fputs( line, stdout );

	return 0;
}
