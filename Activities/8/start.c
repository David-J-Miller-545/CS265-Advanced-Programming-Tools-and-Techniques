/*
 * start.c - a test driver for the List in Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 * NOTES
 *  - you can have more than one driver, to test various functions as you implement them, if desired
 *    - Add other entries similar to `start' to your makefile
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "act8.h"



int main()
{
	elem_t arr[] = { 37, 7, 62, 17, 40, 7, 8, 9, 7, 37} ;

	List l = make_list( arr, 10 ) ;

	printList( l, stdout ) ;
		
	printf("\nSize: %ld\n", size(l));
	printf("\nNums of 40: %ld\n", count(l, 40));
	l = remove_first(l, 37);
	printf("\nremove_first 37 returns: %d\n", l->data);
	printList( l, stdout);
	printf("\n");
	l = remove_all(l, 7);
	printf("\nremove_all 7 returns: %d\n", l->data);
	printList(l, stdout);
	printf("\n\n");

	return 0 ;
}
