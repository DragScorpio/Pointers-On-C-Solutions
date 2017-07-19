/* 8.8-2 */
#include <stdio.h>
float single_tax( float income );
int main( void ) {
	float income1 = 0, income2 = 17000, income3 = 56550,
	      income4 = 81010.5, income5 = 120394.78;
	printf( "%f\n", single_tax( income1 ) );
	printf( "%f\n", single_tax( income2 ) );
	printf( "%f\n", single_tax( income3 ) );
	printf( "%f\n", single_tax( income4 ) );
	printf( "%f\n", single_tax( income5 ) );
	return 0;
}

float single_tax( float income ) {
	float tax[5][4] =
	{
	  { 23350, 0, 0, 0.15 },
	  { 56550, 23350, 3502.50, 0.28 },
	  { 117950, 56550, 12798.50, 0.31 },
	  { 256500, 117950, 31832.50, 0.36 },
	  { 3.4E38, 256500, 81710.50, 0.398 }
	};
	float (*matrix)[4] = tax;
	while( **matrix < income )
		matrix++;

	return matrix[0][2] + matrix[0][3] * (income - matrix[0][1]);
}
