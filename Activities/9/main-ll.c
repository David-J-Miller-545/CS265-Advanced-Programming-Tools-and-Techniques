/********************************************************************************
 * main-ll.c -- test driver for list-based stack
 *
 * Kurt Schmidt
 * NOV 2020
 *
 * gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0, on
 * GNU/Linux 4.15.0-117-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 ********************************************************************************/

#include <stdio.h>

#include "stack-ll.h"


int main()
{
	stack ben ;
	init( &ben ) ;
	ELEM r ;

	if( ! isEmpty( &ben ))
		fputs( "Newly init'd stack is not empty.\n", stderr ) ;

	push( &ben, 13 ) ;

	if( isEmpty( &ben ))
		fputs( "Just inserted, but stack is empty.\n", stderr ) ;

	push( &ben, 12 ) ;
	push( &ben, 5 ) ;

	if( (r=pop(&ben)) != 5 )
		fprintf( stderr, "1st pop, expected 5, got %d\n", r ) ;
	if( (r=pop(&ben)) != 12 )
		fprintf( stderr, "2nd pop, expected 12, got %d\n", r ) ;
	if( (r=pop(&ben)) != 13 )
		fprintf( stderr, "3rd pop, expected 13, got %d\n", r ) ;

	if( ! isEmpty( &ben ))
		fputs( "After all pops, stack is not empty.\n", stderr ) ;

	fputs( "\nDone!\n\n", stdout ) ;

	return 0 ;
}

