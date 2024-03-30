/*	File: commandProcess.h
*
*	Purpose: Header file that contains declarations for functions commandProcess, findID, and printData
*				to be used by functions declared within databaseInteraction.h for the utility program 265inventory.
*				These functions process and execute given commands.
*
*	Author: David Miller
*	Date: 28 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

// Purpose: Takes a command and a pointer to an itemNode linked list, if the command is print, it prints it.
//				If the command is either add or remove it validates that the given id belongs to an item within
//				the given linked list. Converts the string squantity to an int, and either adds it to the quantity
//				of an item or removes it from the quantity of an item if the item has enough to lose. Returns 0 if
//				the command was executed successfully, 3 if the given id is unknown, or 4 if the quantity was more
//				than an item had to lose.
// Preconditions: Takes 4 arguments: 1. A pointer to an itemNode within a linked list, presuming the head of the list.
//						2. A string that represents a valid command keyword. 3. A string that represents and item id.
//						4. A string that is able to be converted to an integer that represents a quantity.
// Postconditions: Processes given command, either prints the given linked list, adds or removes the given quantity to
//						 the given item, or doesn't modify anything if the command was invalid.
//						 Returns an integer: 0 if execution was successful, 3 if unknown ID, and 4 if insufficient quantity
//						 was provided.
int commandProcess(itemNode* data, char* command, char* id, char* squantity);

// Purpose: Traverses through a given linked list of itemNodes and searched for a given id, returns a pointer to the
//				node containing the id, if not found then NULL.
// Preconditions: Takes 2 arguments: 1. A pointer to an itemNode within a linked list, presuming the head of the list. 
//						2. A string representing an item id.
// Postconditions: Returns a pointer to the node containing the id, if it wasn't found then returns NULL.
itemNode* findID (itemNode* data, char* id);

// Purpose:	Traverses through a given linked list of itemNodes and prints the data they contain in a formatted table.
// Preconditions: A pointer to an itemNode within a linked list, presuming the head of the list.
// Postconditions: Prints a neatly formatted table of the data that was within the itemNode linked list.
void printData(itemNode* data); 
