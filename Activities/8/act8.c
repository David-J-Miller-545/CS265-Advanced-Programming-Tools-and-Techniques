/*
 * act8.c - implementations for list functions, Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "act8.h"


void printList( List p, FILE* fout ) 
{
	fputs( "<", fout ) ;
	if( p!=NULL )
	{
		fprintf( fout, "%hd", p->data ) ;
		p = p->next ;
	}
	while( p!=NULL )
	{
		fprintf( fout, ", %hd", p->data ) ;
		p = p->next ;
	}
	fputs( ">", fout ) ;
}


List make_list( elem_t a[], size_t n )
{
	List rv = NULL ;

	if( n==0 )
		return rv ;
	
	rv = make_list( a+1, n-1 ) ;

	sNode* t = (sNode*) malloc( sizeof( sNode )) ;
	if( t==NULL ) return NULL ;

	t->data = a[0] ;
	t->next = rv ;
	rv = t ;

	return rv ;
}


List rand_list( size_t n )
{
	if( n==0 )
		return NULL ;

	List rv = NULL ;
	sNode *t = NULL ;
	
	for( size_t i=0; i<n; ++i )
		;
}

void freeList( List l )
{
	sNode* p = NULL ;
	while( l!=NULL )
	{
		p = l->next ;
		free( l ) ;
		l = p ;
	}
}

size_t size( List l ) 
{
	size_t rv = 0 ;
	while( l != NULL){
		l = l->next;
		rv++;
	}
	return rv;
}

size_t count(sNode* n, elem_t t){
	size_t rv = 0 ;
	while( n != NULL){
		if (n->data == t) rv++;	
		n = n->next;	
	}
	return rv;
}


sNode* remove_first(sNode* n, elem_t t ){	
	size_t len = 1;	
	sNode* start = n;
	sNode* previous = n;			
	
	while( n != NULL && n->data != t){		
		len++;
		previous = n;	
		n = n->next;	
	}
	if (n->data == t) {
		previous->next = n->next;
		previous = n;
		n = n->next;
		free (previous);
		previous = NULL;
	}
	return (len == 1) ? n : start;
}

sNode* remove_all(sNode* n, elem_t t){
	size_t len = 1;	
	sNode* start = n;
	sNode* previous = n;			
	
	while( n != NULL ){		
		if (n->data == t) {
			previous->next = n->next;
			previous = n;
			n = n->next;
			start = (len == 1) ? n : start;
			free (previous);	
		}
		len++;
		previous = n;	
		n = n->next;	
	}	
	return start;
}
