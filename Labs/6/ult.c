#include <stdio.h>

int main() {
	int num;
	printf("Please input an integer >> ");
	scanf("%d", &num);
	for (int n = num; n>0; n--){
		for (int i = n; i>0; i--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
