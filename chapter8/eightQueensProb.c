/* 8.8-8 */
#include <stdio.h>
/*backtracking:
**
**
*/
int place8queens( int chessboard[8][8], int row, int init_pos );
void clearChessboard( int chessboard[8][8] );
void printChessboard( int chessboard[8][8] );
int main( void ) {
	int init_pos;  /* the first QUEEN is always placed at the first row;
			* init_pos is its column number */
	int chessboard[8][8] = { {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0} };

	for( init_pos = 0; init_pos < 8; init_pos++ ) {
		if( place8queens( chessboard, 8, init_pos ) ) {
			printChessboard( chessboard );
			printf( "%s\n", "Solution found!!!" );
		}
		else
			printf( "No solution if first QUEEN position: ( 0, %i )\n", init_pos );

		clearChessboard( chessboard );
	}
/*
	if( place8queens( chessboard, 8 ) )
		printChessboard( chessboard );
	else
		printf( "%s\n", "no solution found!" );
*/
	return 0;
}

void clearChessboard( int chessboard[8][8] ) {
	int i, j;
	for( i = 0; i < 8; i++ ) {
		for( j = 0; j < 8; j++ )
			chessboard[i][j] = 0;
	}
}

int place8queens( int chessboard[8][8], int row, int init_pos ) {
	int col, prev_row, prev_col, next_col;
	if( row == 1 ) {
		chessboard[0][init_pos] = 1;
		printChessboard( chessboard );
		printf( "\n\n" );
		return 1;
	}

	if( place8queens( chessboard, row - 1, init_pos ) ) {
		for( col = 0; col < 8; col++ ) {
			for( prev_row = row - 2, prev_col = col - 1, next_col = col + 1; prev_row > -1; prev_row--, prev_col--, next_col++ ) {
				/* check if there is QUEEN in the same column, or, there is QUEEN along the diagonal */
				if( chessboard[prev_row][col] == 1 )
					break;

				if( ( prev_col > -1 ) && ( chessboard[prev_row][prev_col] == 1 ) )
					break;

				if( ( next_col < 8 ) && ( chessboard[prev_row][next_col] == 1 ) )
					break;
			}

			if( prev_row == -1 ) {
				chessboard[row - 1][col] = 1;
				printChessboard( chessboard );
				printf( "\n\n" );
				return 1;
			}
		}
	}
	/* return 0 if no position for QUEEN found after searching all columns */
	return 0;
}

void printChessboard( int chessboard[8][8] ) {
	int i, j;
	for( i = 0; i < 8; i++ ) {
		for( j = 0; j < 7; j++ )
			printf( " %i |", chessboard[i][j] );

		printf( " %i \n", chessboard[i][j] );
		if( i - 7 ) {
			for( j = 0; j < 7; j++ )
				printf( "%s ", "---" );

			printf( "%s\n", "---" );
		}
	}
}
