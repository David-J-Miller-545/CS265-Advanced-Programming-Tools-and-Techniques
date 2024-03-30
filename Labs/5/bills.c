#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char *d = NULL;	
	size_t len = 0 ;

   printf( "Please a dollar amount => " ) ;
   getline( &d, &len, stdin ) ;
		
	int ones = atoi(d);

	int twenties = ones / 20;
	ones = ones % 20;
	int tens = ones / 10;
	ones = ones % 10;
	int fives = ones / 5;
	ones = ones % 5;

	printf("\n$20 bills:%4d\n$10 bills:%4d\n$ 5 bills:%4d\n$ 1 bills:%4d\n\n", twenties, tens, fives, ones);
	return 0;
}
