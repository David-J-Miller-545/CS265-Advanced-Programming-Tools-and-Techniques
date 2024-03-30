#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char *user = NULL;
	user = getenv("USER");
	char *c = NULL;
	c = getenv("COLUMNS");
	int cols;
	cols = atoi(c);
	printf("Hello, there, %s!\tThis terminal is %d columns wide.\n", user, cols);
	return 0;
}
