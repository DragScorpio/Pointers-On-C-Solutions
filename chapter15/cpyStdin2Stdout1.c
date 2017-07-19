/* 15.21-2 */
#include <stdio.h>
#define MAX_LINE_LEN 80

int main( void ) {
	char text_line[MAX_LINE_LEN];

	while( fgets( text_line, MAX_LINE_LEN, stdin ) != NULL ) {
		fputs( text_line, stdout );
	}

	return 0;
}
