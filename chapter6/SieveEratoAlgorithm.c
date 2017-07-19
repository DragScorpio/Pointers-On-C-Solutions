/* 6.18-4 */
#include <stdio.h>
#define maxNum 1001
/* the range of prime number will be from 2 to maxNum - 1 */
void initList( char list[], int n );
void PrintPrime( char list[], int n );
void SieveOfEratosthenes( char list[], int n );
int main( void ) {
	int n = maxNum;
	char list[n];
	SieveOfEratosthenes( list, n );
	PrintPrime( list, n );
	return 0;
}

void initList( char list[], int n ) {
	int i = 2;
	while( i < n )
		list[i++] = 1;
}

void SieveOfEratosthenes( char list[], int n ) {
	initList( list, n );
	char* start = &list[2];
	char* next = start;
	do {
		if( *start ) {
			while( ( next += start - list ) <= &list[n - 1] )
				*next = 0;
		}
	} while( ( next = ++start ) <= &list[n - 1] );
}

void PrintPrime( char list[], int n ) {
	char *prime = &list[2];
	int i = 2;
	while( i++ < n ) {
		if( *prime++ )
			printf( "%i ", i - 1 );
	}
}
