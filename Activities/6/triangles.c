/***-*-C-*-****************************************
 * triangles.c -- Given leg dimension, integer n, prints out 4 right triangles
 *
 * Kurt Schmidt
 * APR 2021
 *
 * tcc version 0.9.27 (x86_64 Linux)
 *
 *****************************************************/

#include <stdio.h>

void lr( size_t n )
{
	for (size_t num = 1; num<(n+1); num++){
		for (size_t i = (n - num); i>0; i--) {
			printf(" ");
		}
		for (size_t i = num; i>0; i--) {
			printf("*");
		}
		printf("\n");
	}


}

void ll( size_t n )
{
	for (size_t num = 1; num<(n+1); num++){
		for (size_t i = 0; i<num; i++) {
			printf("*");
		}
		printf("\n");
	}

}

void ul( size_t n )
{
	for (size_t num = n; num>0; num--){
		for (size_t i = num; i>0; i--) {
			printf("*");
		}
		printf("\n");
	}

}

void ur( size_t n )
{
	for (size_t num = n; num>0; num--){
		for (size_t i = (n - num); i>0; i--) {
			printf(" ");
		}
		for (size_t i = num; i>0; i--) {
			printf("*");
		}
		printf("\n");
	}


}

int main( int argc, char* argv[] )
{
	size_t  n ;

	sscanf( argv[1], "%zu", &n ) ;

	// fprintf( stderr, "\n### We got a %zu for n\n", n ) ;

	fputs( "\n", stdout ) ;
	ll( n ) ;
	fputs( "\n", stdout ) ;
	lr( n ) ;
	fputs( "\n", stdout ) ;
	ul( n ) ;
	fputs( "\n", stdout ) ;
	ur( n ) ;
	fputs( "\n", stdout ) ;

	return 0 ;
}
