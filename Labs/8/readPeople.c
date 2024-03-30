/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 100

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person* a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a[], size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[CAP] = { NULL } ; /* rest are initialised to 0 */

	
	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] ) ;
			exit( 1 ) ;
		}
	}	

	readPeople( team, fin ) ;
	
	for (size_t i = 0; i<CAP; i++) {
		if (*(team+i) == NULL) break;
		printf("Person #%ld\nLast: %s\nFirst: %s\nAge: %d\n", (i+1), team[i]->last, team[i]->first, team[i]->age);
	}
	
	
//	printf("Person #%d\nLast: %s\nFirst: %s\nAge: %d\n", 1, team[0]->last, team[0]->first, team[0]->age);

	freePeople( team, CAP ) ;	


	return 0 ;
}

void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;

	while( getline( &buff, &len, f ) > 1 ) 
	{
		person* someone = (person*) malloc(sizeof(person));	
		
		sscanf(buff, "%s", someone->last);
		getline( &buff, &len, f );
		sscanf(buff, "%s", someone->first);
		getline( &buff, &len, f );
		sscanf(buff, "%d", &(someone->age));

		*(a+cnt) = someone;

		++cnt ;
	}

	free( buff ) ;
}

void freePeople( person* a[], size_t n ) 
{	
	for (size_t i = 0; i < n; ++i) {
		if (*(a+i) != NULL) free(*(a+i));			
		*(a+i) = NULL;
	}	
	a = NULL;
}
