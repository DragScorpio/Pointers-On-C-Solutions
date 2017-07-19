/* 16.14-4 */
#include <stdio.h>
#include <time.h>

int main( int argc, char **argv ) {
/* command line input format: [prog_name month day year] */
	char const *weekday[7] = { "Sunday", "Monday", "Tuesday", "Wednesday",
				"Thursday", "Friday", "Saturday" };
	unsigned int month, day, year;
	time_t rawtime;
	struct tm *timeinfo;
	if( argc != 4 )
		return 1;

	sscanf( argv[1], "%u", &month );
	sscanf( argv[2], "%u", &day );
	sscanf( argv[3], "%u", &year );

	time( &rawtime );
	timeinfo = localtime( &rawtime );
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	timeinfo->tm_year = year - 1900;
	mktime( timeinfo );

	printf( "Today is %s\n", weekday[timeinfo->tm_wday] );
	return 0;
}
