#include <stdio.h>

// Purpose: Find a target value in a given array and return a pointer value to that target.
// Preconditions: An array of ints, the array length, and a target value within the integer
// Postconditions: A pointer to either the target if found, or NULL if not.

int* arrFind(int* ints, size_t len, int target) {
	for (size_t i = 0; i < len; i++) {
		if (*(ints+i) == target) {
			return ints+i;
		}
	}
	return NULL;
}

int main() {
	int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t n = 10;

	for (size_t i = 0; i < n; i++) {
		int target = *(test+i) + 2;

		int* result = arrFind(test, n, target);
		printf("Result is: %d\n", *result);
	}

	return 0;
}
