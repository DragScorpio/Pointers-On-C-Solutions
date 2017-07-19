/* 4.14-3 */
#include <stdio.h>
char* whichTriangle( int a, int b, int c );
int main( void ) {
	int a, b, c;
	char ch;
	printf("%s\n", "please enter 3 numbers that are lengths of a triangle's sides:");
	scanf("%d%c%d%c%d", &a, &ch, &b, &ch, &c);
	printf("this is %s triangle\n", whichTriangle( a, b, c ));
	return 0;
}

char* whichTriangle( int a, int b, int c ) {
	char* msg;
	int isTriangle = ( a + b > c ) && ( a + c > b ) && ( b + c > a);
	if( isTriangle ) {
		if( a == b || b == c || a == c ) {
			if( a + b == 2 * c )
				msg = "a equilateral";
			else
				msg = "a isosceles";
		}
		else
			msg = "a scalene";
	}
	else
		msg = "not a";

	return msg;
}
