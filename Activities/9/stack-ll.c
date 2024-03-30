/********************************************************************************
 * stack-ll.c -- implementation for stack functions (built over a linked list)
 *
 * Kurt Schmidt
 * NOV 2020
 *
 * gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0, on
 * GNU/Linux 4.15.0-117-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 * NOTES (Invariants):
 *	- Stack is empty iff stack's head ptr is NULL
 *
 ********************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "stack-ll.h"


void init( stack* s )
{
	s->head = NULL;
	return ;
}

void kill( stack* s )
{
	sNode *p = s->head, *q ;
	while( p != 0 ) 
	{
		q = p->next ;
		free( p ) ;
		p = q ;
	}
}

_Bool isEmpty( const stack* s ) 
{
	return s->head == NULL ;
}

void push( stack* s, ELEM i ) 
{
	sNode* new = (sNode*) malloc(sizeof(sNode));	
	new->data = i;
	new->next = s->head;
	s->head = new;
}

ELEM pop( stack* s ) 
{
	sNode* popped = s->head;
	s->head = s->head->next;
	ELEM value = popped->data;
	free(popped);
	return value ;
}

ELEM top( const stack* s ) 
{
	return s->head->data ;
}

