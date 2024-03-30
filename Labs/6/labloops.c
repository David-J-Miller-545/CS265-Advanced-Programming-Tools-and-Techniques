#include <stdio.h>

int main() {
	printf("Q2.1)\n");
	int i, j;
	for( i=5, j=(i-1); ((i>0) && (j>0)); --i, --j ){
		printf( "%d ", i );
	}
	/*	
	printf("Q2.2)\n");
	for( i=10; i>=1; i/=2 ){
		printf( "%d\n", i++ );
	}
	*/

	char resp = 'y' ;
	while( resp != 'n' && resp!= 'N' )
	{
	   // processing...

	   printf( "\nEnter another input? (y/[n]) => " ) ;
      // the space preceding the %c tells scanf to skip whitespace
	   scanf( " %c", &resp ) ;
	} 

	return 0;

	printf(
}
