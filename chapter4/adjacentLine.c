/* 4.14-5 */
#include <stdio.h>
#include <string.h>
#define max_length 128

int main( void ) {
	FILE *pFile;
	char thisLine[128];
	char nextLine[128];
	pFile = fopen( "testfile.txt", "r" );

	if( pFile == NULL )
		perror( "Error opening file" );
	else {
		fgets( thisLine, max_length, pFile );
		while( feof(pFile) == 0 ) {
			if( fgets( nextLine, max_length, pFile ) == NULL )
				break;
			else if( strcmp( thisLine, nextLine ) == 0 ) {
				printf("%s", thisLine );
				while( strcmp( thisLine, nextLine ) == 0 )
					fgets( thisLine, max_length, pFile );
			}
			else
				strcpy( thisLine, nextLine );
		}
	}
	fclose(pFile);

	return 0;
}
