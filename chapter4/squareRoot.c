/* 4.14-1 */
#include <stdio.h>
double sqroot( int n );
int main( void ) {
	int n;
	printf("%s\n", "Please enter a positive number:");
	scanf("%d", &n);
	printf("the result is: %f\n", sqroot( n ));
	return 0;
}

double sqroot( int n ) {
	double a[n];
	/* the approximations array */
	a[0] = 1.000; /* the first approximation is 1.000 */
	int i = 0;
	while( i < n ) {
		a[i + 1] = ( a[i] + n / a[i] ) / 2;
		i += 1;
	}

	return a[i - 1];
}
