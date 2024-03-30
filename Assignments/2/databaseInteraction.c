/*	File: databaseInteraction.c
*
*	Purpose:	Contains definitions for functions openDatabase, commandInterface, and closeDatabase
*				to be used by the utility program 265inventory. Handles all interactions between
*				the program, database, and user.
*
*	Author: David Miller
*	Date: 29 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "265inventory.h"
#include "commandProcess.h"
#include "commandParse.h"
#include "databaseInteraction.h"

itemNode* openDatabase(char databaseFilename[]) {
	FILE* f = fopen(databaseFilename, "r");

	char* in = NULL;
	size_t len ;
	itemNode* start = (itemNode*) malloc(sizeof(itemNode));
	itemNode* node = start;		
	itemNode* nextNode = start;

	while (getline(&in, &len, f) > 1) {
		node->next = nextNode;	
		node = node->next; 	
		strcpy(node->id, strtok(in, " : "));
		sscanf(strtok(NULL, " : "), "%hi", &(node->qty));
		strcpy(node->desc, strtok(NULL, "\n"));
	
		nextNode = (itemNode*) malloc(sizeof(itemNode));	
	} 	
	node->next = NULL;
	free(nextNode);
	free(in);	

	fclose(f);	

	return start;
}

void commandInterface(itemNode* data) {
	char *command = NULL ;
	char id[16];
	char quantity[27];	
	size_t len ;	
	short status = 0;	
	
	
	while (status != -1) {	
		printf("%% ");	
		if (getline(&command, &len, stdin) > 1) {			
			command[(strlen(command) - 1)] = '\0';		
			status = commandParse(command, id, quantity);	
		}

		else status = 2;

		if (status == 0) {
			status = commandProcess(data, command, id, quantity);
			if (status == 0) printf("ACK\n");
			if (status == 3) printf("NAK Unknown Item\n");
			if (status == 4) printf("NAK Insufficient Quantity\n");
		}
		else if (status == 1) printf("NAK Incorrect Syntax.\n");
		else if (status == 2) printf("Unrecognised command\n");
	}		
	free(command);
}


void closeDatabase(itemNode* list, char dataFilename[]) {
	itemNode* prev;
	char filename[] = "tmpdat.XXXXXX";
	int fileDesc = mkstemp(filename);		
	FILE* f = fdopen(fileDesc, "w");

	while (list != NULL) {
		fprintf(f, "%s:%hi:%s\n", list->id, list->qty, list->desc);	
		prev = list;
		list = list->next;
		free(prev);	
		prev = NULL;
	}	

	rename(filename, dataFilename);	

	fclose(f);	
}

