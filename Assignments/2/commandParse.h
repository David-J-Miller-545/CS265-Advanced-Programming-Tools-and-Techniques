/*	File: commandParse.h
*
*	Purpose: Header file that contains the declaration of the function commandParse to be used by the function
*				commandInterface declared within databaseInteraction.h for the utility program 265inventory.
*				This function takes a given user command entry, splits it into a command that can be processed,
*				and validates it.
*
*	Author: David Miller
*	Date: 28 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

// Purpose: Given a user command entry, splits it into a command that can be processed, and validates it.
// Preconditions: A string representing the user command entry, a string representing id to modify, and a string
//						representing a quantity to modify.
// Postconditions: Given user command entry is now split. The string command is now the command keyword.
//						 The given strings id and quantity are now modified containing information from the command split.
//						 Returns -1 if quit, 0 if syntax is valid, 1 if syntax invalid, and 2 if command is unknown.
int commandParse(char command[], char id[], char quantity[]);
