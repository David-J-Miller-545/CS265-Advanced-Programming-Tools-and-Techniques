

// Purpose: 
// Preconditions: 
// Postconditions: 
void closeDatabase(itemNode* list, FILE* data) {
	itemNode* prev;
	char* filename = "tmpdat.XXXXXX";
	int fileDesc = mkstemp(filename);	
	f = fdopen(fileDesc, "w");

	while (list->next != NULL) {
		fprintf(f, "%s:%hi:%s\n", list->id, list->qty, list->desc);
		prev = list;
		list = list->next;
		free(prev);
		prev = NULL;
	}
	free(list);
	list = NULL;

	rename(filename, data);
}
