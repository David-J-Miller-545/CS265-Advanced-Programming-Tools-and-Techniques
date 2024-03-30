/*	File: databaseInteraction.h
*
*	Purpose: Header file that contains declarations for functions openDatabase, commandInterface, and closeDatabase
*				to be used by the utility program 265inventory. Handles all interactions between
*				the program, database, and user.
*
*	Author: David Miller
*	Date: 28 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

// Purpose: Takes the name of a database file, reads through it, translates the data into a linked list, and returns
//				a pointer to the first node in the list.
// Preconditions: A string that is a valid filename to a database that contains data in the format <id>:<qty>:<desc>
// Postconditions: Returns a pointer to the first node of a linked list translated from the contents of that database
// 					 file.
itemNode* openDatabase(char databaseFilename[]); 

// Purpose: Given a pointer to a linked list, handles user inputted commands, processes them, and applies them to
//				the given linked list. Keeps accepting user input until the "quit" command is given.
// Preconditions: Takes a pointer to a linked list, presumably the head. Assumes stdin will not reach EOF.
// Postconditions: Passes given user command into the function commandParse which is declared in commandParse.h.
//						 Then depending on if the command was found valid in commandParse it passes the now split
//						 command information to be processed and applied to the linked list via the function commandProcess
//						 which is declared within the file commandProcess.h.
//						 Prints the following to stdout: "% " for the beginning of every command line, "ACK" for after a
//						 successful command, "Unrecognised command" if a given command was not recognised,
//						 "NAK Incorrect syntax." if a given command did not have correct syntax, "NAK Unknown Item" if
//						 the id given within the given command did not match any id within nodes of the list, and
//						 "NAK Insufficient Quantity" if the given command was "remove" and was trying to remove more items,
//						 then there were available. Runs until the "quit" command is given.
void commandInterface(itemNode* data);

// Purpose: Takes a pointer to a linked list and a database filename, prints the list to a temp file, frees the list as
//				it is being iterated through, and renames the temp file to the name of the database filename given, 
//				overwritting any data that file stored if it already existed.
// Preconditions: Takes 2 arguments: 1. a pointer to a linked list, presumably the head. 2. A string that could be a
//						file name.
// Postconditions: Prints data from list to a temp file, renames the temp file to the given database filename,
//						 frees the given linked list.
void closeDatabase(itemNode* list, char dataFilename[]); 
