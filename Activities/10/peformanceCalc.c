#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

	FILE* f = fopen("data.csv", "r");

	char* in = NULL;
	size_t len ;
	char* ptr;

	double Q = 0;
	double n = 0;

	fprintf(stdout, "n | Q(n) | Q(n)/n | Q(n)/(n^2) | Q(n)/(n^2.75) | Q(n)/(n^3)\n");
	while (getline(&in, &len, f) > 1) {
		n = strtod(strtok(in, ","), &ptr);
		Q = strtod(strtok(NULL, ","), &ptr);
	
		fprintf(stdout, "%0.2lf | %0.2lf | %0.4lf | %0.4lf | %0.4lf | %0.4lf\n", n, Q, Q/n, Q/(n*n),
		Q/(pow(n, 2.75)), Q/(n*n*n));		
		
	}

	free(in);
	fclose(f);

	return 0;
}
