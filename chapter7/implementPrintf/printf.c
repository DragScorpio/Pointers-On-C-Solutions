/* 7.11-5-implementation */
#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

void print_format( char* format, ... ) {
	va_list input;
	va_start( input, format );
	char ch, *str, errorMsg[128] = "specifier not identified...[%d, %f, %c, %s]\n";
	int val;
	float fval;
	while( ( ch = *format ) && *format++ != '%' )
		putchar( ch );
	switch( *format++ ) {
		case 'd':
			val = va_arg( input, int );
			print_integer( val );
			print_string( format ); /* print the rest of format string */
			break;
		case 'f':
			fval = va_arg( input, double );
			print_float( fval );
			print_string( format );
			break;
		case 'c':
			val = va_arg( input, int );
			putchar( val );
			print_string( format );
			break;
		case 's':
			str = va_arg( input, char* );
			print_string( str );
			print_string( format );
			break;
		default:
			print_string( errorMsg );
	}
	va_end( input );
}

void print_integer( int val ) { // recursive
	if( val / 10 )
		print_integer( val / 10 );
	putchar( ( val % 10 ) + '0' );
}

void print_float( float val ) { // precision: 0.00000
	int i = (int) val, j = 0;
	float res = val - i;
	print_integer( i );
	putchar( '.' );
	while( j++ < 5 ) {
		res *= 10;
		i = (int)res % 10;
		putchar( i + '0' );
		res -= i;
	}
}

void print_string( char* str ) {
	while( *str )
		putchar( *str++ );
}
