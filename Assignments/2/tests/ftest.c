#include <stdio.h>
#include <stdlib.h>

int main() {
	char filename[] = "tmp-XXXXXX";
	int fd = mkstemp(filename);

	FILE* f = fdopen(fd, "w");
	fprintf(f, "hello there\n:)");
	fclose(f);
				    
	rename(filename, "hello.txt");

	return 0;
}
