/* 4.14-2 */
#include <stdio.h>
int isPrime( int n );
int main( void ) {
	int i;
	for(i = 0; i < 101; i += 1) {
		if( isPrime( i ) )
			continue;
		else
			printf("%d\n", i);
	}
	return 0;
}

int isPrime( int n ) {
	if( n == 1 )
		return 0;
	else if( n == 0 )
		return 1;
	else {
		int i, num_of_divisor = 0;
		for( i = 2; i < n; i += 1 ) {
			if( n%i == 0 )
				num_of_divisor += 1;
		}
		return num_of_divisor;
	}
}
