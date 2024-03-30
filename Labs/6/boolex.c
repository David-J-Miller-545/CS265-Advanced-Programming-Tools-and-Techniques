#include <stdio.h>


int main() {
	int i = 5 ,
		j = 12 ,
    	k = -13 ,
    	z = 0 ;

	printf("a. j < i == %s\n", (j < i) ? "1" : "0"); 
	printf("b. ! j < i == %s\n", (! j < i) ? "1" : "0");
	printf("c. (! j) < i == %s\n", ((! j) < i) ? "1" : "0");
	printf("d. i + j == %s\n", (i + j) ? "1" : "0");
	printf("e. !i + j == %s\n", (!i + j) ? "1" : "0");
	printf("f. !!i + !j == %s\n", (!!i + !j) ? "1" : "0");
	printf("g. j && k == %s\n", (j && k) ? "1" : "0");
	printf("h. i && j || z == %s\n", (i && j || z) ? "1" : "0");
	printf("i. i && ( j || z ) == %s\n", (i && ( j || z )) ? "1" : "0");

	return 0;
}
