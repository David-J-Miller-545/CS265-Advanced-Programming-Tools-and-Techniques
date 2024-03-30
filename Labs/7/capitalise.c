#include <stdio.h>
#include <ctype.h>

// Purpose: Takes a null-terminated string (char*), and replaces each lower-case letter with its upper-case counterpart.
// Preconditions: A string
// Postconditions: A capitalized string

void capitalise(char* string) {	
	for (size_t i = 0; *(string+i) != '\0'; ++i) {
		if (islower(*(string+i))) {	
			*(string+i) = toupper(*(string+i));	
		}	
	}
}

int main() {
	char word[] = "poggers1234";
	capitalise(word);
	printf("%s\n", word);

	return 0;
}
