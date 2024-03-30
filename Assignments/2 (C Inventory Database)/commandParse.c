/*	File: commandParse.c
*
*	Purpose: Contains the definition of the function commandParse to be used by the function commandInterface
*				declared within databaseInteraction.h for the utility program 265inventory. This function takes
*				a given user command entry, splits it into a command that can be processed, and validates it.
*
*	Author: David Miller
*	Date: 29 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

#include <string.h>
#include <ctype.h>

#include "commandParse.h"

int commandParse(char command[], char id[], char quantity[]) {

	// ---KEYWORD---
	char* token = strtok(command, " ");

	// If the keyword is not known return 1
	if (strcmp(token, "add") != 0 && strcmp(token, "remove") != 0 && strcmp(token, "quit") != 0 && strcmp (token,
	"print") != 0) return 2;		

	// If the keyword is quit, return -1
	if (strcmp(command, "quit") == 0) return -1;

	// If the keyword is print check that there are no other characters after, if so return 1, otherwise 0
	if (strcmp(command, "print") == 0){
		if (strtok(NULL, "\0") != NULL) return 1;
		else return 0; // Command is valid, return 0
	}

	// ---ID---
	token = strtok(NULL, ":");
	// If the token is NULL
	if (token == NULL) return 1;
	// If the ID can not fit in the allotted array size, return 1
	if (strlen(token) > 15) return 1;

	strcpy(id, token); // ID is valid

	// ---QUANTITY---
	token = strtok(NULL, "\0");
	// If the token is NULL
	if (token == NULL) return 1;
	// If there is anything other than a digit in the rest if the command, return 1
	for (size_t i = 0; i < strlen(token); i++) if (! isdigit(token[i])) return 1;

	strcpy(quantity, token); // The rest of the string was a number
	
	return 0; // Command is valid, return 0
}
