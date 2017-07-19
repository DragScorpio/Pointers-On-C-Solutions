/* 2.8-1 */
#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main( void ) {
	printf("%d\n", increment( 10 ));
	printf("%d\n", increment( 0 ));
	printf("%d\n", increment( -10 ));
	printf("%d\n", negate( 10 ));
	printf("%d\n", negate( 0 ));
	printf("%d\n", negate( -10 ));
	return 0;
}
