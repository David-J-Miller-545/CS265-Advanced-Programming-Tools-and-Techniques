#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int commandParse(char command[], char id[], char quantity[]);

int main() {
	char testCommand[100];
	char id[16];
	char quantity[100];

	strcpy(testCommand, "add 928352:42");
	
	printf("\nTest Command: %s\n", testCommand);
	int test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "print");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "quit a b a");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "fun");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "add 1234567899999999:23");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "print fail");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);

	strcpy(testCommand, "add 123456:7 r");
	printf("\nTest Command: %s\n", testCommand);
	test = commandParse(testCommand, id, quantity);
	printf("Command Status: %d\nKeyword: %s\nID: %s\nQuantity: %s\n", test, testCommand, id, quantity);


	printf("\n");

	return 0;
}
// Purpose: 
// Preconditions: 
// Postconditions: Given command is now just the keyword, given id and quantity are modified.
//						 Returns -1 if quit, 0 if syntax is valid, and 1 if syntax invalid
int commandParse(char command[], char id[], char quantity[]) {

	// ---KEYWORD---
	char* token = strtok(command, " ");
	// If the keyword can not fit in the allotted array size, return 1
	if (strlen(token) > 6) return 1;

	// If the keyword is not known return 1
	else if (strcmp(token, "add") != 0 && strcmp(token, "remove") != 0 && strcmp(token, "quit") != 0 && strcmp (token,
	"print") != 0) return 1;		

	// If the keyword is quit, return -1
	if (strcmp(command, "quit") == 0) return -1;

	// If the keyword is print check that there are no other characters after, if so return 1, otherwise 0
	if (strcmp(command, "print") == 0){
		if (strtok(NULL, "\0") != NULL) return 1;
		else return 0; // Command is valid, return 0
	}

	// ---ID---
	token = strtok(NULL, " : ");
	// If the ID can not fit in the allotted array size, return 1
	if (strlen(token) > 15) return 1;

	strcpy(id, token); // ID is valid

	// ---QUANTITY---
	token = strtok(NULL, "\0");
	// If there is anything other than a digit in the rest if the command, return 1
	for (size_t i = 0; i < strlen(token); i++) if (! isdigit(token[i])) return 1;

	strcpy(quantity, token); // The rest of the string was a number
	
	return 0; // Command is valid, return 0
}
