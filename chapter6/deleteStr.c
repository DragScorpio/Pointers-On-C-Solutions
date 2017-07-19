/* 6.18-2 */
#include <stdio.h>

int del_substr( char *str, char const *substr );
char* isSubstr( char *str, char const *substr );
int main( void ) {
/* 1. basic tests: */
	char str0[128] = "ABCDEFG";
	char str1[128] = "ABCDEFG";
	char str2[128] = "ABCDEFG";
	char str3[128] = "ABCDEFG";
	char str4[128] = "hello, kitty! This is Xiangzhen Sun.. er.. greetings!\n";
	char const substr0[128] = "FGH";
	char const substr1[128] = "CDF";
	char const substr2[128] = "XABC";
	char const substr3[128] = "CDE";
	char const substr4[128] = " Xiangzhen Sun.. er.. gre";
	if( del_substr( str0, substr0 ) )
		printf( "%s\n", str0 );
	else
		printf( "%s\n", "NULL" );

	if( del_substr( str1, substr1 ) )
                printf( "%s\n", str1 );
        else
                printf( "%s\n", "NULL" );

	if( del_substr( str2, substr2 ) )
                printf( "%s\n", str2 );
        else
                printf( "%s\n", "NULL" );

	if( del_substr( str3, substr3 ) )
                printf( "%s\n", str3 );
        else
                printf( "%s\n", "NULL" );

	if( del_substr( str4, substr4 ) )
                printf( "%s\n", str4 );
        else
                printf( "%s\n", "NULL" );

/* 2. advanced tests: */
	char str[128], substr[128];
	printf( "%s\n", "please enter a string:" );
	fgets( str, 128, stdin );
	printf( "%s\n", "please enter a substring:");
	fgets( substr, 128, stdin );
	char const *subs = substr;
	if( del_substr( str, subs ) )
                printf( "%s\n", str );
        else
                printf( "%s\n", "NULL" );

	return 0;
}

int del_substr( char *str, char const *substr ) {
	/* no modifications to str if empty substr */
	if( *substr == '\0' )
		return 1;

	char *head;
	char *tail;
	if( ( tail = isSubstr( str, substr ) ) != NULL ){
	/* tail points to the char right after the matching substring in str */
		head = tail;
		while( *substr++ != '\0' )
	/* head points to the first char of the matched substring in str */
			head--;

		do {
			*head++ = *tail;
		} while( *tail++ != '\0' );

		return 1;
	}
	else
		return 0;
}

char* isSubstr( char *str, char const *substr ) {
/* this function decides if substr is a sub-string of str
   on success, it returns a pointer that points to the char
   right after the matching piece of substring of the original string */
	char const *subptr = substr;
	char *sptr;
	while( *( sptr = str++ ) != 0 ) {
		while( *sptr == *subptr ) {
			sptr++;
			subptr++;
		}
		if( *subptr == 0 )
			return sptr;
		else
			subptr = substr;
	}
	return NULL;
}
