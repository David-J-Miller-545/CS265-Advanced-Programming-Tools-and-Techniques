#include <stdio.h>

int main () {
	int i = 5;
	int j = 3;
	int a;

	i += j;
	printf("i += j == %d\n", i);
	i = 5;
	j = 3;
	i = j++;
	printf("i = j++ == %d\n", i);
	i = 5;
	j = 3;
	i = ++j;
	printf("i = ++j == %d\n", i);
	i = 5;
	j = 3;
	a = i % j;
	printf("%d\n", a);
	i = 5;
	j = 3;
	a = i % j++;
	printf("%d\n", a);

	return 0;
}
