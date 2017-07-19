/* 16.14-6 */
#include <stdio.h>
#include <math.h>

/* amount: amount of loan
** interest: interest per period as a percentage (eg: 12% --> 12 )
** year: duration of loan
*/
double payment( double amount, double interest, int year );
int main( int argc, char **argv ) {
	double amount, interest;
	int year;
	sscanf( argv[1], "%lf", &amount );
	sscanf( argv[2], "%lf", &interest );
	sscanf( argv[3], "%i", &year );
	printf( "Your monthly payment is $%.2lf\n", payment( amount, interest, year ) );
	return 0;
}

double payment( double amount, double interest, int year ) {
	double I, N;
	I = interest / 12;
	N = year * 12;
	return amount * I / ( 1 - pow( 1 + I, 0 - N ) );
}
