/* 17.10-11 */
#include "generic_stack.h"

DECLARE_GENERIC_STACK( int );
DEFINE_GENERIC_STACK( int );
DECLARE_GENERIC_STACK( float );
DEFINE_GENERIC_STACK( float );

int main( void ) {
	GENERIC_STACK( int ) *si1 = NULL;
	GENERIC_STACK( int ) *si2 = NULL;

	GENERIC_STACK( float ) *sf1 = NULL;
	GENERIC_STACK( float ) *sf2 = NULL;

	int i;
	float f;
/* test push() */
	/* push 1 to 10 to the stack pointed by si1 */
	for( i = 1; i < 11; i++ ) {
		push_int( i, &si1 );
	}

	/* push 20 to 29 to the stack pointed by si2 */
	for( i = 20; i < 30; i++ ) {
		push_int( i, &si2 );
	}

	/* push 0.2 to 1.0 to the stack pointed by sf1, step == 0.2 */
	for( f = 0.2; f < 1.2; f += 0.2 ) {
		push_float( f, &sf1 );
	}

	/* push 0.5 to 4.5 to the stack pointed by sf2, step == 0.5 */
	for( f = 0.5; f < 5; f += 0.5 ) {
		push_float( f, &sf2 );
	}

/* test top(), pop(), is_empty() */
	/* dump and print elements of stack si1 */
	while( !is_empty_int( si1 ) ) {
		printf( "%i ", top_int( si1 ) );
		pop_int( &si1 );
	}
	printf( "\n\n" );

	/* dump and print elements of stack si2 */
	while( !is_empty_int( si2 ) ) {
		printf( "%i ", top_int( si2 ) );
		pop_int( &si2 );
	}
	printf( "\n\n" );

	/* dump and print elements of stack sf1 */
	while( !is_empty_float( sf1 ) ) {
		printf( "%.1f ", top_float( sf1 ) );
		pop_float( &sf1 );
	}
	printf( "\n\n" );

	/* dump and print elements of stack sf2 */
	while( !is_empty_float( sf2 ) ) {
		printf( "%.1f ", top_float( sf2 ) );
		pop_float( &sf2 );
	}
	printf( "\n\n" );

	return 0;
}
