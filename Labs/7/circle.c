#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double PI ;

int main( int argc, char* argv[] ) 
{
	PI = 4*atan(1) ;  // Compute Pi.  Use *all* the digits available
	
	char *ptr;
	double r, A ;

	if( argc<3 )
	{
		fputs( "Need 2 arguments, a name and a radius.\n\n", stderr ) ;
		return 1 ;
	}

	r = strtod( *(argv+2), &ptr ) ;

	A = PI * r * r;  // π r^2

	printf( "%s, your area is %.4e units square\n\n", *(argv+1), A ) ;

	return 0 ;
}
		
