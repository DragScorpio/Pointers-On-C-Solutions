/* 6.18-1 */
#include <stdio.h>

char const* find_char( char const *source, char const *chars );
int main( void ) {
	char const source1[128] = "A,B,C,D,E,F,G";
	char const chars1[128] = "XYG";
	char const chars2[128] = "JURYE";
	char const chars3[128] = "QQFQQ";
	char const chars4[128] = "XRCQEF";
	char const* ptr = find_char( source1, chars1 );
	if( ptr == NULL )
		printf( "%s\n", "NULL" );
	else
		printf( "%c\n", *ptr );

	ptr = find_char( source1, chars2 );
        if( ptr == NULL )
                printf( "%s\n", "NULL" );
        else
                printf( "%c\n", *ptr );

	ptr = find_char( source1, chars3 );
        if( ptr == NULL )
                printf( "%s\n", "NULL" );
        else
                printf( "%c\n", *ptr );

	ptr = find_char( source1, chars4 );
        if( ptr == NULL )
                printf( "%s\n", "NULL" );
        else
                printf( "%c\n", *ptr );

	return 0;
}

char const* find_char( char const *source, char const *chars ) {
	char const* cptr;
	if( source != NULL && chars != NULL ) {
		while( *source != '\0' ) {
			for( cptr = chars; *cptr != '\0'; cptr++ ) {
				if( *cptr == *source )
					return source;
			}
			source++;
		}
	}
	return NULL;
}
