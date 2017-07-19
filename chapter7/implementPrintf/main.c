/* 7.11-5-main.c */
/* test cases */
#include <stdio.h>
#include "printf.h"

int main( void ) {
	char ch = 'X';
	int val = 1289;
	double fval = 213.04391;
	char str[128] = "Hello, world! This is Xiangzhen Sun";
	print_format( "the character is: %c\n",ch );
	print_format( "the integer is: %d\n", val );
	print_format( "the float number is: %f\n", fval );
	print_format( "the string is: %s\n", str );
	/* error tests */
	print_format( "the string is: %k\n", str );
	print_format( "the string is: ", str );
	return 0;
}
