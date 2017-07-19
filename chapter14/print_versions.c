/* 14.10-1 */
#include <stdio.h>
#define OPTION_LONG
#define OPTION_DETAILED

void print_ledger_long( int x ) {
        printf( "call-->print_ledger_long\n" );
}

void print_ledger_detailed( int x ) {
        printf( "call-->print_ledger_detailed\n" );
}

void print_ledger_default( int x ) {
        printf( "call-->print_ledger_default\n" );
}
void print_ledger( int x ) {
#ifdef OPTION_LONG
	#define OK 1
	print_ledger_long( x );
#endif

#ifdef OPTION_DETAILED
	#define OK 1
	print_ledger_detailed( x );
#endif

#ifndef OK
	print_ledger_default( x );
#endif
}

int main( void ) {
	print_ledger( 5 );
	return 0;
}
