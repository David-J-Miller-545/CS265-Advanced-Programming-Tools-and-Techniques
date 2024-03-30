/*
 * mystring.h - interface for my (your) string functions.
 *   We are implementing some of the C Standard Library string functions
 *    - for practice with arrays
 *    - to introduce multiple-file compiles
 *      - and the use of header (.h) files
 *    - discuss further the difference between a function definition and a function declaration (prototype)
 *      - in fact, we'll declare (only) a variable, and define it elsewhere
 *
 * David Miller
 * May 2021
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 on
 * GNU/Linux 5.4.0-66-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 * NOTES:
 *  - Do NOT compile this file directly
 *    - Just #include it where it's needed
 *  - The __MY_STRING_H__ lines keep this file from being included multiple times
 *    - (in the same compilation unit)
 *    - Pre-processor directives
 *  - b_LUCKY is only declared (not defined) here, because of "extern"
 *    - Says to compiler that it's defined elsewhere
 *    - It's declared here simply for type checking
 *    - It is not defined here
 *      - No space is put aside
 *      - Can NOT initialise here
 *    - It must be defined in ! one .c file
 *      - It must also be initialised then (because it's const)
 *  - Prototypes automatically have `extern' linkage
 *    - You may specify it:
 *      extern size_t mystrlen( const char* ) ;
 *    - *I* don't, but, I'm not suggesting you shouldn't
 *      - see your project's style guide
 *  - Corresponding definitions can be in ANY .c file
 *    - Probably found in mystring.c
 *    - But, purely convention
 *  - This file is available to the client
 *    - Good place for helpful (not effusive!) comments
 */


#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <stddef.h>

	/* Example of declaring (not defining) a variable in a header file */
extern const unsigned short b_LUCKY ;  // great place for units, if appropriate

	// mystrlen - returns length of string
	// INPUTS: a null-terminated character array
	// OUTPUT: (I already specified, in the description, so, maybe don't need this line)
	// Side-effects: NONE
size_t mystrlen( const char* ) ;
void mystrcpy( char* t, const char* s ) ;
void mystrcat( char* t, const char* s ) ;


// TODO  As you add more functions to mystring.c, put their prototypes (with comments) here
//   *Above* the #endif line


#endif  /* __MY_STRING_H__ */
