/* 13.10-5 */
#include <stdio.h>
#include <string.h>

char **do_args( int argc, char **argv, char *control,
                void (*do_arg)( int ch, char *value ), void (*illegal_arg)( int ch ) );

void doArg( int ch, char *value );
void illegalArg( int ch );
void print_result( char **argv, char **arg );
int main( int argc, char **argv ) {
	char **ret;
//	char *control1 = "x";
//	char *control2 = "x+y+z+";
//	char *control3 = "ab+cdef+g";
	char *control4 = "abcdef";
	ret = do_args( argc, argv, control4, doArg, illegalArg );
	print_result( argv, ret );
	return 0;
}

char **do_args( int argc, char **argv, char *control,
		void (*do_arg)( int ch, char *value ), void (*illegal_arg)( int ch ) ) {
	char *chr; /* chr points to the next char to be processed in a single argument */
	char *str; /* points to the char that is found in control */
	while( *++argv != NULL && **argv == '-' ) {
	/* skip prog name to see if the next cmd line argument starts with a '-' */
		while( *( chr = ++*argv ) != '\0' ) {
		/* for each char in the current argument after the '-' */
			if( ( str = strchr( control, *chr ) ) != NULL ) {
			/* the char is found in control */
				if( str[1] == '+' ) {
				/* the char is followed by a '+' */
					if( chr[1] != '\0' ) {
					/* there are some char in the current argument */
						do_arg( *chr, chr+ 1 );
						break;
					}
					else {
					/* there isn't any char in the current argument */
						if( argv[1] != NULL ) {
						/* next cmd line argument is not NULL */
							do_arg( *chr, *++argv );
							break;
						}
						else {
							illegal_arg( *chr );
							break;
						}
					}
				}
				else /* the char is not followed by a '+' */
					do_arg( *chr, NULL );
			}
			else /* the char is not found in control */
				illegal_arg( *chr );
		}
	}
	return argv; /* return a pointer to the next cmd line argument */
}

void doArg( int ch, char *value ) {
	printf( "call: (*do_arg)( %c, \"%s\" )\n", ch, value );
}

void illegalArg( int ch ) {
	printf( "call: (*illegal_arg)( '%c' )\n", ch );
}

void print_result( char **argv, char **arg ) {
	printf( "return: &argv[%i]\n", (int)(arg - argv) );
}
