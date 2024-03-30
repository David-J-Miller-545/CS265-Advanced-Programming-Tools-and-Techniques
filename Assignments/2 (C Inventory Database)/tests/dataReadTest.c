#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct itemNode itemNode ;

struct itemNode {
   char id[16] ;
   unsigned short qty ;
   char desc[31] ;
	itemNode *next ;
} ;

itemNode* databaseParse(FILE* f);
void closeDatabase(itemNode* list, char* dataFilename);

int main() {
	FILE *file = fopen( "sample.dat", "r" );
	itemNode* data = databaseParse(file);
	itemNode* List = data;

	printf("\n\n");
	while(List->next != NULL) {
		printf("\nID: %s\nQty: %hi\nDesc: %s\n\n", List->id, List->qty, List->desc);
		List = List->next;
	}

	List = data;

	printf("hi!!");
	closeDatabase(List, "sampinv.dat");
	printf("why?!");

	//if (List == NULL) printf ("Head of List is freed!, who knows about the rest though...\n");
	/*else {

	printf ("List = %ld\n", List);
		
	while(List->next != NULL) {
		printf("\nID: %s\nQty: %hi\nDesc: %s\n\n", List->id, List->qty, List->desc);
		List = List->next;
	}

	}
	*/

	return 0;
}

// Purpose: 
// Preconditions: 
// Postconditions: 
itemNode* databaseParse(FILE* f) {
	char* buff = NULL;
	size_t len ;
	itemNode* start = (itemNode*) malloc(sizeof(itemNode));
	itemNode* node = start;		
	
	while (getline(&buff, &len, f) > 1) {
	strcpy(node->id, strtok(buff, " : "));
	sscanf(strtok(NULL, " : "), "%hi", &(node->qty));
	strcpy(node->desc, strtok(NULL, "\n"));
	
	itemNode* nextNode = (itemNode*) malloc(sizeof(itemNode));
	node->next = nextNode;
	node = node->next;

	} 
	free(node);
	node = NULL;

	return start;
}

void closeDatabase(itemNode* list, char* dataFilename) {	
	itemNode* prev;
	//char* filename = "tmp.XXXXXX";
	//int fileDesc = mkstemp(filename);	
	//FILE* f = fdopen(fileDesc, "w");

	while (list != NULL) {
		//fprintf(f, "%s:%hi:%s", list->id, list->qty, list->desc);
		fprintf(stdout, "%s:%hi:%s", list->id, list->qty, list->desc);
		prev = list;
		list = list->next;
		free(prev);	
		prev = NULL;
	}

	//rename(filename, dataFilename);	
}

