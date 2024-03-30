/*	File: 265inventory.h
*
*	Purpose: This is the header file containing itemNode datatype which is a struct that contains data to create the
*				database linked list the utility program 265inventory uses.
*
*	Author: David Miller
*	Date: 28 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

typedef struct itemNode itemNode ;

struct itemNode {
   char id[16] ;
   unsigned short qty ;
   char desc[31] ;
	itemNode *next ;
} ;


