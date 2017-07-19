#include <stdio.h>
/* this test file verifies my preliminary knowledge on c-pointers */
int main( void ) {
	char string[128] = "hello, world!\nI am coming!\n";
	char *ch = string;
	char *next = ch;
	while( *next != 0 ) {/* or, *next != '\0' */
		putchar( *next );
		ch += 1;
		next = ch;
	}
	printf("%s", string );
	return 0;
}
