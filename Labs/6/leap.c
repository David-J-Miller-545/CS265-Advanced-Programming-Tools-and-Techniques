/* Program: leap.c
	Purpose: Prompts the user for a year (as an int), prints YES if the input year is a leap year, and NO otherwise.
	Author: David Miller
*/
#include <stdio.h>

int main() {
	int year;

	printf( "Please input a year >> " );
	scanf("%d", &year);	

	((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) ? printf("YES\n") : printf("NO\n");

	return 0;
}
