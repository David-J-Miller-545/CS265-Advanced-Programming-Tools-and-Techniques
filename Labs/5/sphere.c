/*
 * sphere-pow.c - Demonstration of reading a float (double) cmd-line arg, and linking in libmath
 * - Needs radius of sphere as command-line arg
 * - Result will be cubic units of radius
 *
 * gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0, on
 * GNU/Linux 5.19.0-32-generic x86_64
 *
 * EDITOR:  120 cols, tabstop=2
 *
 * NOTES:
 *  Compile:  link in the math library:
 *			$ gcc sphere-pow.c -lm
 *		NOT
 *			$ gcc -lm sphere-pow.c
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double PI ;

int main( int argc, char* argv[] ) 
{
	PI = 4*atan(1) ;  // Compute Pi.  Use *all* the digits available

	double r, V ;

	if( argc<2 )
	{
		fputs( "Need the radius, as an argument.", stderr ) ;
		return 1 ;
	}

	r = atof( argv[1] ) ;

	V = 4 * PI * r * r * r / 3 ;  // 4/3 π r^3

	printf( "\nThe volume of the sphere with radius %f is %.2e\n\n", r, V ) ;

	return 0 ;
}
		
