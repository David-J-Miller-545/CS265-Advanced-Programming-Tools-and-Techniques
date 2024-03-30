#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "hello-my-name:is-david";
	char* token = strtok(str, "-");
	printf("%s\n", token);
	printf("%s\n", str);
	char * newstr = str+strlen(str)+1;
	printf("%s\n", newstr);
	token = strtok(NULL, "-");
	printf("%s\n", token);
	token = strtok(NULL, "\0");
	printf("%s\n", token);

	return 0;
}
