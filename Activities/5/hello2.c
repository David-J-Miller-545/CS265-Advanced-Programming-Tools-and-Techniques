#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char *user = NULL;
	user = getenv( "USER" );
	printf("Hello, there, %s!\n", user);
	return 0;
}
