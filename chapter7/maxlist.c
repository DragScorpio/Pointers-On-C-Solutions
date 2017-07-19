#include <stdio.h>
#include <stdarg.h>
int max_list( int n_values, ... );
int main( void ) {
	printf( "%i\n", max_list( 7, 1, 3, 10, 2, 55, 23, 10 ) );
	return 0;
}

int max_list( int n_values, ... ) {
	va_list value; /* create a var list */
	int val, max = 0, i = 0;
	va_start( value, n_values );
	/* initialize va_list: value, to accept vars after n_values */
	do {
		if( max < (val = va_arg( value, int ) ) )
		/* each loop, va_arg() takes in one more var */
			max = val;
	} while( ++i < n_values );
	va_end( value );
	return max;
}
