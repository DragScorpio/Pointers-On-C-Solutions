/* 16.14-3 */
#include <stdio.h>
#include <time.h>

int main( void ) {
	time_t cur_time;
	struct tm *timeinfo;
	timeinfo = localtime( &cur_time );
	printf( "the thumb is on the %i, the index finger is on the %i, the little finger is on the %i\n",
		timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec );
	return 0;
}
