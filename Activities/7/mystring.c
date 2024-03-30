/*
 * mystring.c - implementation of my (your) string functions.
 *
 * <your name>
 * May 2021
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 on
 * GNU/Linux 5.4.0-66-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 * NOTES
 *  - We include stddef.h so the compiler can check that the functions here jibe with the declarations in our contract
 *    - the <> indicate a standard library header file
 *      - the compiler knows where to search
 *    - A .h file in quotes is a user-defined file
 *      - Should be in (relative to) CWD
 *      - Should come after all system and standard includes
 *  - To compile
 *        gcc -c mystring.c
 *    - yields mystring.o (object file)
 *    - -c says "compile only"
 *    - does not link
 *  - You can use an s* much like an s[].
 *    - s[3] is valid (if length of string > 4)
 *
 */

#include <stddef.h>

#include "mystring.h"


  /* It's a const, it must be initialised */
const unsigned short b_LUCKY = 1<<10 ;


size_t mystrlen( const char* s ) 
{
	size_t rv = 0 ;

	while (s[rv] != '\0') {
		++rv;
	}

	return rv ;
}

void mystrcpy(char* t, const char* s) 
{
	size_t rv = 0 ;

	while (s[rv] != '\0') {
		t[rv] = s[rv];
		++rv;
	}
	t[rv] = '\0';
}


void mystrcat(char* t, const char* s) 
{
	size_t ts = 0 ;
	size_t rv = 0 ;

	while (t[ts] != '\0') {
	      ++ts;
	}

	while (s[rv] != '\0') {
		t[ts + rv] = s[rv];
		++rv;
	}
	t[ts + rv] = '\0';
}
