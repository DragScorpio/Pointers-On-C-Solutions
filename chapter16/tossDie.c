/* 16.14-2 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int toss_die( void );
int main( void ) {
	printf( "You tossed %i points!\n", toss_die() );
	return 0;
}

int toss_die( void ) {
	srand( time( NULL ) );
	return rand() % 6 + 1;
}
