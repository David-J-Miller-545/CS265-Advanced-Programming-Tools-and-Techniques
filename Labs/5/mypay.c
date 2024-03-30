#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *buff = NULL ;
   size_t len = 0 ;

   printf( "Please enter the subtotal => " ) ;
   getline( &buff, &len, stdin ) ;
 
   double subtotal = atof(buff);
	double tax = subtotal * .06;
	double tip = subtotal * .20;

	double total = subtotal + tax + tip;

   printf( "\n        Bill\n" );
	printf("~~~~~~~~~~~~~~~~~~~~\n");
	printf("  Subtotal:%7.2f\n  Tax:%12.2f\n  Tip:%12.2f\n\n  Total:%10.2f\n",subtotal, tax, tip, total);
	printf("~~~~~~~~~~~~~~~~~~~~\n\n");

   free( buff ) ;
	return 0 ;
}
