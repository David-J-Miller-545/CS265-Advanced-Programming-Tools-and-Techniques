/*	File: 265inventory.c
*
*	Purpose: This is the main driver for the utility program 265inventory
*
*	Author: David Miller
*	Date: 29 November, 2023
*
*	Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
*	Kernel: Linux tux1 5.15.0-83-generic #92-Ubuntu SMP Mon Aug 14 09:30:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux
*/

#include "265inventory.h"
#include "databaseInteraction.h"

int main() {
	
	char databaseFilename[] = "inv.dat";
	
	itemNode* dataList = openDatabase(databaseFilename);	
	commandInterface(dataList); 	
	closeDatabase(dataList, databaseFilename);	

	return 0;

}
