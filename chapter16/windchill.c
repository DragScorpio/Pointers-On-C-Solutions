/* 16.14-5 */
#include <stdio.h>
#include <math.h>
#define A 10.45
#define B 10
#define C -1
#define X 1.78816

double wind_chill( double temp, double velocity );
int main( int argc, char **argv ) {
	double temp, velocity;
	sscanf( argv[1], "%lf", &temp );
	sscanf( argv[2], "%lf", &velocity );
	printf( "the wind chill is %.2lf\n", wind_chill( temp, velocity ) );
	return 0;
}

double wind_chill( double temp, double velocity ) {
	return ( A + B * sqrt( velocity ) + C * velocity ) * ( 33 - temp ) / ( A + B * sqrt( X ) + C * X );
}
