#include <stdio.h>

// Purpose: Takes an array of doubles , along with the array's length (as a size_t), and computes the arithmetic mean,
// 			max, and min, as doubles.
// Preconditions: An array of doubles and the length of the array
// Postconditions: Modifies the values of pointers min, max, and mean

void arrStats(double* doubles, size_t len, double* min, double* max, double* mean)
{	
	for (size_t i = 0; i < len; i++) {
		*mean += doubles[i];
		if (i == 0) {
			*min = *(doubles+i);
			*max = *(doubles+i);
		}
		*min = (*min > *(doubles+i)) ? *(doubles+i) : *min;
		*max = (*(doubles+i) > *max) ? *(doubles+i) : *max;
	}
	*mean /= len;	
}

int main() {
	double doubles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t len = 10;
	double min;
	double max;
	double mean;

	arrStats(doubles, len, &min, &max, &mean);
	printf("Min: %lf\tMax: %lf\tMean: %lf\n", min, max, mean);
	
	return 0;
}
