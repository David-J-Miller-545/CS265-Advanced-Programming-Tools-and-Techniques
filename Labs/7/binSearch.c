#include <stdio.h>


// Purpose: Takes an array of integers , along with n, the number of elements in the array (as a size_t), and an int to
// 			search for (target), and returns the index of the target element if found, n otherwise.
// Preconditions: Array of ints, size of array n, target int within the array.
// Postconditions: Index of target if found, otherwise the size of the array n.

size_t binSearch(int* ints, size_t n, int target) {
	size_t lowerBound = 0;	
	size_t upperBound = n - 1;
	size_t currentMid = n / 2 - 1;
	while (upperBound != 0 && lowerBound <= upperBound) {
		
		if ( *(ints+currentMid) == target ) {
			return currentMid;
		}
		else if ( *(ints+currentMid) < target ) {	
			lowerBound = currentMid + 1;
			currentMid = (upperBound - lowerBound) / 2 + lowerBound;
		}
		else if ( *(ints+currentMid) > target) {
			upperBound = currentMid - 1;	
			currentMid = upperBound - (upperBound - lowerBound) / 2;
		}
	}

	return (*(ints+currentMid) == target) ? currentMid : n;
}		

int main() {
	int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t n = 10;

	for (size_t i = 0; i < n; i++) {
		int target = *(test+i);

		size_t result = binSearch(test, n, target);
		printf("Result is: %ld\n", result);
	}

	return 0;
}
