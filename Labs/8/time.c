#include <stdio.h>

struct time
{
	int hr ;
	int min ;
	int sec ;
};

struct time sec2hms( int secs ) {
	struct time out;
	out.hr = secs / 3600;
	secs = secs % 3600;
	out.min = secs / 60;
	out.sec = secs % 60;

	return out;
}

int main() {
	struct time test = sec2hms( 67896 );
	printf("\nHours:%d\t\tMinutes%d\t\tSeconds:%d\n", test.hr, test.min, test.sec);

	return 0;
}
