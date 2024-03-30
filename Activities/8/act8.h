/*
 * act8.h - interface for list functions, Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 */

#ifndef __KS_ACT_8_H_
#define __KS_ACT_8_H_

#include <stdlib.h>
#include <stdio.h>

typedef short elem_t ;	// list of shorts

typedef struct sNode sNode ;

struct sNode {
	sNode* next ;
	elem_t data ;
} ;

typedef sNode* List ;

	// make_list - creates list, given sequence of n elements in a
	// Note, returned list must be returned to the heap
List make_list( elem_t a[], size_t n ) ;

/*** TODO together ***/

	// Note, we're cheating here.  We need to know format specifier for item_t.  Assume it's a short
void printList( List, FILE* ) ;

void freeList( List ) ;

/*** TODO ***/

size_t size( List ) ;
size_t count( List, elem_t t ) ;
List remove_first( List, elem_t t ) ;
List remove_all( List, elem_t t ) ;

#endif  // __KS_ACT_8_H_

