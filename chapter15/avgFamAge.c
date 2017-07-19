/* 15.21-7 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 80

float avg( int sum, int num );
int main( void ) {
	FILE *data;
	char line[MAX_LENGTH];
	int i, num, sum, age[10] = {0};

	data = fopen( "family.txt", "r" );
	if( data == NULL ) {
		perror( "family.txt" );
		exit( EXIT_FAILURE );
	}

	while( fgets( line, MAX_LENGTH, data ) != NULL ) {
		num = sscanf( line, " %d %d %d %d %d %d %d %d %d %d ", age, age + 1, age + 2, age + 3,
			      age + 4, age + 5, age + 6, age + 7, age + 8, age + 9 );

		for( sum = 0, i = 0; i < num; i++ )
			sum += age[i];

		if( num > 0 )
			printf( "Family age data: %s--Average age: %5.2f\n", line, avg( sum, num ) );
	}

	fclose( data );
	return 0;
}

float avg( int sum, int num ) {
	return (float)sum / num;
}
