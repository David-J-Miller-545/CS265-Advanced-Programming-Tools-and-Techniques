#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct sNode sNode ;

struct sNode {
	sNode* next ;
	short data ;
} ;

typedef sNode* List ;


size_t listLength(const sNode *L);

sNode* listRev(sNode *L);

sNode* make_list( short a[], size_t n )
{
	sNode* rv = NULL ;

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

void printList( sNode* p, FILE* fout ) 
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



int main() {
	short listArr[] = {1, 2, 3, 4, 5};
	sNode* List = make_list( listArr, 5);

	printf("Our List\n");
	printList(List, stdout);
	size_t len = listLength(List);
	printf("\nList Length = %ld\n" , len);
	sNode* revList = listRev(List);
	printf("Reversed List\n");
	printList(revList, stdout);
	printf("\n");
	return 0;
}

size_t listLength(const sNode *L){
	size_t len = 1;	
	while(L->next != NULL) {
		L = L->next;
		len++;
	}
	return len;
}

sNode* listRev(sNode *L){
	sNode* current = L;
	sNode* previous = L;
	sNode* next = current->next;
	
	current->next = NULL;	
	current = next;

	while(current->next != NULL) {	
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	current->next = previous;
	return current;
}
