/* 9.14-15 */
#include <stdio.h>
#include <string.h>

void dollars( char *dest, char const *src );
void reverse_string( char *string );
int main( void ) {
	char amount1[10] = "", amount2[10] = "9", amount3[10] = "75",
	     amount4[10] = "321", amount5[10] = "9760", amount6[10] = "15782",
	     amount7[10] = "135201", amount8[10] = "1202011", amount9[15] = "91352010",
	     amount10[15] = "998135201", amount11[20] = "1123413635201";

	char dest[20];
	dollars( dest, amount1 );
	printf( "%s\n", dest );
	dollars( dest, amount2 );
        printf( "%s\n", dest );
	dollars( dest, amount3 );
        printf( "%s\n", dest );
	dollars( dest, amount4 );
        printf( "%s\n", dest );
	dollars( dest, amount5 );
        printf( "%s\n", dest );
	dollars( dest, amount6 );
        printf( "%s\n", dest );
	dollars( dest, amount7 );
        printf( "%s\n", dest );
	dollars( dest, amount8 );
        printf( "%s\n", dest );
	dollars( dest, amount9 );
        printf( "%s\n", dest );
	dollars( dest, amount10 );
        printf( "%s\n", dest );
	dollars( dest, amount11 );
        printf( "%s\n", dest );

	return 0;
}

void dollars( char *dest, char const *src ) {
/* assumption: string dest contains only digits */
	char *dst;
	int len = strlen( src );

	if( len > 2 ) {
		dst = dest;
		src = src + len - 1;  /* direct src to the char before NUL */
		*dest++ = *src--;
		*dest++ = *src--;
		*dest++ = '.';
		len -= 2;

		for( ; len > 3; len -= 3 ) {
			*dest++ = *src--;
			*dest++ = *src--;
			*dest++ = *src--;
			*dest++ = ',';
		}

		for( ; len > 0; len-- )
			*dest++ = *src--;

		*dest = '\0';
		reverse_string( dst );
	}
	else {
		switch( len ) {
			case 2:
				*dest++ = '0';
				*dest++ = '.';
				*dest++ = *src++;
				*dest++ = *src++;
				*dest = *src;
				break;
			case 1:
				*dest++ = '0';
				*dest++ = '.';
				*dest++ = '0';
				*dest++ = *src++;
				*dest = *src;
				break;

			case 0:
				*dest++ = '0';
				*dest++ = '.';
				*dest++ = '0';
				*dest++ = '0';
				*dest = 0;
				break;
			default:
				printf( "%s\n", "Error amount..." );
		}
	}
}

void reverse_string( char *string ) {
	char temp, *start, *end;
	int len = strlen( string );

	for( start = string, end = string + len - 1; start < end; start++, end-- ) {
		temp = *start;
		*start = *end;
		*end = temp;
	}
}
