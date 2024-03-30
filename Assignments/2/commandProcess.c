/*	File: commandProcess.c
*
*	Purpose:	Contains definitions for functions commandProcess, findID, and printData to be used by functions
*				declared within databaseInteraction.h for the utility program 265inventory. These functions 
*				process and execute given commands.
*
*	Author: David Miller
*	Date: 29 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "265inventory.h"
#include "commandProcess.h"


int commandProcess(itemNode* data, char* command, char* id, char* squantity) {
	if (strcmp(command, "print") == 0) {
		printData(data);
		return 0;
	}

	int quantity = atoi(squantity); 
	itemNode* processingNode = findID(data, id);
	if (processingNode == NULL) return 3;

	if (strcmp(command, "add") == 0) processingNode->qty += quantity;
	else if (strcmp(command, "remove") == 0) {
		if (processingNode->qty < quantity) return 4;
		else processingNode->qty -= quantity;
	}

	return 0;
}

itemNode* findID (itemNode* data, char* id) {
	while(data->next != NULL) {
		if (strcmp(data->id, id) == 0) return data;
		data = data->next;
	}
	if (strcmp(data->id, id) == 0) return data;
	else return NULL;
}

void printData(itemNode* data) {	
	printf("  %-32s%-9s%s\n", "DESC", "QTY", "ID");	
	printf("------------------------------  -------  ----------------\n");	

	while (data != NULL) {
		printf("%-30s   %5hi    %s\n", data->desc, data->qty, data->id);
		data = data->next;
	}
}

