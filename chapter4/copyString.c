/* 4.14-4 */
#include <stdio.h>
#define max_num 3
void copy_n( char dst[], char src[], int n );
int main( void ) {
	char src[] = "hello, world!"; /* test: src size is always 14 */
	char dst[14];
	copy_n( dst, src, max_num );
	printf("%s\n", dst);
	return 0;
}

void copy_n( char dst[], char src[], int n ) {
	char *ch = src;
	int i = 0;
	while( ch != 0 && i < n ) {
		dst[i] = *ch;
		ch += 1;
		i += 1;
	}
	while( i < n )
		dst[i] = '\0';
}
