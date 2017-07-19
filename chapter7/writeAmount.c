/* 7.11-6 */
/* unsigned int ranges from 0 to 4 295 967 295( 43 billion ) */
#include <stdio.h>
#include <string.h>
#define TEN 10
#define TWENTY 20
#define HUNDRED 100
#define THOUSAND 1000
#define MILLION 1000000
#define BILLION 1000000000

void written_amount( unsigned int amount, char* buffer );
void belowHundred( unsigned int amount, char* buffer );
void Hundred( unsigned int amount, char* buffer );
void Thousand( unsigned int amount, char* buffer );
void Million( unsigned int amount, char* buffer );
void Billion( unsigned int amount, char* buffer );
void ones( unsigned int amount, char* buffer );
void tenTOnineteen( unsigned int amount, char* buffer );
void tens( unsigned int amount, char* buffer );

int main( void ) {
	char buffer[128] = "";
	unsigned int amount;
	printf( "%s\n", "please give a positive integer" );
	scanf( " %u", &amount );
	written_amount( amount, buffer );
	printf( "%s\n", buffer );
	return 0;
}

void written_amount( unsigned int amount, char* buffer ) {
	if( amount < HUNDRED )
		belowHundred( amount, buffer );
	else if( amount >= HUNDRED && amount < THOUSAND )
		Hundred( amount, buffer );
	else if( amount >= THOUSAND && amount < MILLION )
		Thousand( amount, buffer );
	else if( amount >= MILLION && amount < BILLION )
		Million( amount, buffer );
	else
		Billion( amount, buffer );
}

void belowHundred( unsigned int amount, char* buffer ) { /* 0 - 99 */
	unsigned int ones_value;
	unsigned int tens_value;
	if( amount < TEN )
		ones( amount, buffer );
	else if( amount >= TEN && amount < TWENTY )
		tenTOnineteen( amount, buffer );
	else {
		tens_value = amount / TEN;
		ones_value = amount % TEN;
		tens( tens_value, buffer );
		if( ones_value ) {
			strcat( buffer, "-" );
			ones( ones_value, buffer );
		}
	}
}

void Hundred( unsigned int amount, char* buffer ) { /* 100 - 999 */
	unsigned int hundreds_value = amount / HUNDRED;
	ones( hundreds_value, buffer );
	strcat( buffer, " hundred" );
	if( ( amount -= hundreds_value * HUNDRED ) ) {
		strcat( buffer, " and " );
		belowHundred( amount, buffer );
	}
}

void Thousand( unsigned int amount, char* buffer ) { /* 1000 - 999999 */
	unsigned int thousands_value = amount / THOUSAND;
	thousands_value < HUNDRED ? belowHundred( thousands_value, buffer ) : Hundred( thousands_value, buffer );
	strcat( buffer, " thousand" );
	if( ( amount -= thousands_value * THOUSAND ) ) {
		strcat( buffer, " " );
		Hundred( amount, buffer );
	}
}

void Million( unsigned int amount, char* buffer ) { /* 1000000 - 999999999 */
	unsigned int millions_value = amount / MILLION;
	millions_value < HUNDRED ? belowHundred( millions_value, buffer ) : Hundred( millions_value, buffer );
	strcat( buffer, " million" );
	if( ( amount -= millions_value * MILLION ) ) {
		strcat( buffer, " " );
		Thousand( amount, buffer );
	}
}

void Billion( unsigned int amount, char* buffer ) { /* 1000000000 - 43000000000 */
	unsigned int billions_value = amount / BILLION;
	belowHundred( billions_value, buffer );
	strcat( buffer, " billion" );
	if( ( amount -= billions_value * BILLION ) ) {
		strcat( buffer, " " );
		Million( amount, buffer );
	}
}

void ones( unsigned int amount, char* buffer ) {
        switch( amount ) {
                case 0:
			strcat( buffer, "" );
                        break;
                case 1:
                        strcat( buffer, "one" );
                        break;
                case 2:
                        strcat( buffer, "two" );
                        break;
                case 3:
                        strcat( buffer, "three" );
                        break;
                case 4:
                        strcat( buffer, "four" );
                        break;
                case 5:
                        strcat( buffer, "five" );
                        break;
                case 6:
                        strcat( buffer, "six" );
                        break;
                case 7:
                        strcat( buffer, "seven" );
                        break;
                case 8:
                        strcat( buffer, "eight" );
                        break;
                case 9:
                        strcat( buffer, "nine" );
                        break;
	}
}

void tenTOnineteen( unsigned int amount, char* buffer ) {
	switch( amount ) {
		case 10:
			strcat( buffer, "ten" );
			break;
		case 11:
                        strcat( buffer, "eleven" );
                        break;
		case 12:
                        strcat( buffer, "twelve" );
                        break;
		case 13:
                        strcat( buffer, "thirteen" );
                        break;
		case 14:
                        strcat( buffer, "fourteen" );
                        break;
		case 15:
                        strcat( buffer, "fifteen" );
                        break;
		case 16:
                        strcat( buffer, "sixteen" );
                        break;
		case 17:
                        strcat( buffer, "seventeen" );
                        break;
		case 18:
                        strcat( buffer, "eighteen" );
                        break;
		case 19:
                        strcat( buffer, "nineteen" );
                        break;
	}
}

void tens( unsigned int amount, char* buffer ) {
        switch( amount ) {
                case 2:
                        strcat( buffer, "twenty" );
                        break;
                case 3:
                        strcat( buffer,  "thirty" );
                        break;
                case 4:
                        strcat( buffer, "forty" );
                        break;
                case 5:
                        strcat( buffer, "fifty" );
			break;
		case 6:
                        strcat( buffer, "sixty" );
                        break;
                case 7:
                        strcat( buffer, "seventy" );
                        break;
                case 8:
                        strcat( buffer, "eighty" );
                        break;
                case 9:
                        strcat( buffer, "ninety" );
                        break;
        }
}
