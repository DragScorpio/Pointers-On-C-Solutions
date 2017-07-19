/* 8.8-7 */
#include <stdio.h>
#include <stdarg.h>

/*basic assumptions:
**1. arrayinfo is a valid pointer
**2. correct number of subscript-arguments are passed to array_offset
*/

/* ths version array_offset2 applies to arrays with column-major order */
int array_offset2( int arrayinfo[], ... );
int main( void ) { /* test case */
	int arrayinfo[7] = {3,4,6,1,5,-3,3};
	printf( "%d\n", array_offset2( arrayinfo, 4, 1, -3 ) );
	printf( "%d\n", array_offset2( arrayinfo, 5, 1, -3 ) );
	printf( "%d\n", array_offset2( arrayinfo, 6, 1, -3 ) );
	printf( "%d\n", array_offset2( arrayinfo, 4, 2, -3 ) );
	printf( "%d\n", array_offset2( arrayinfo, 4, 3, -3 ) );
	printf( "%d\n", array_offset2( arrayinfo, 4, 1, -2 ) );
	printf( "%d\n", array_offset2( arrayinfo, 4, 1, -1 ) );
	printf( "%d\n", array_offset2( arrayinfo, 5, 3, -1 ) );
	printf( "%d\n", array_offset2( arrayinfo, 6, 5, 3 ) );

	return 0;
}

int array_offset2( int arrayinfo[], ... ) {
	int i, loc, high, low, mul;
	int dim = arrayinfo[0]; /* dimension of pseudo-array: 1 - 10 */
	int subsArray[dim]; /* local array to store subscript arguments */

/* 1st check */
	if( dim < 1 || dim > 10 )
		return -1; /* check dimension is within limit */

/* 2nd check
	if( SIZEOF_ARRAY( arrayinfo ) != 2 * dim + 1 )
		return -1;
	check the correctness of arrayinfo */

	va_list subs;  /* subscript arguments */
	va_start( subs, arrayinfo );

	for( i = 0; i < dim; i++ ) /* copy subscript arguments to subsArray[] */
		subsArray[i] = va_arg( subs, int );

/* 3rd check */
	for( i = 0; i < dim; i++ ) {
	/* check that each subscript arg is within the given limits,
	** and that for each pair of given limits, low-limit < high-limit
	*/
		if( subsArray[i] < arrayinfo[2 * i + 1] ||
		    subsArray[i] > arrayinfo[2 * i + 2] ||
		    arrayinfo[2 * i + 1] > arrayinfo[2 * i + 2] )
			return -1;
	}

	for( loc = 0, i = 0, mul = 1; i < dim; i++, mul *= high - low + 1 ) {
	/* calculate the offset */
		high = arrayinfo[2 * i + 2];
		low = arrayinfo[2 * i + 1];
		loc += ( subsArray[i] - low ) * mul;
	}

	va_end( subs );
	return loc;
}

/*introduction to stdarg.h:
**1. va_list:
**This type is used as a parameter for the macros defined in <cstdarg> to retrieve
**the additional arguments of a function
**va_start initializes an object of this type in such a way that subsequent calls
**to va_arg sequentially retrieve the additional arguments passed to the function
*/
