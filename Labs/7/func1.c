#include <stdio.h>
#include <stdlib.h>


double arrAvg (double* doubles, size_t len) {
	double mean = 0;
	for (int i = 0; i < len; i ++) {
		mean += *(doubles+i);
	}
	mean /= len;
	return mean;
}

int main() {
	char *in = NULL ;
	size_t len ;
	double inputs[100] ;
	size_t cnt = 0;

	while( getline( &in, &len, stdin ) > 1 )
	{
		++cnt;
		sscanf( in, "%lf", &inputs[cnt-1]);
	}

	double mean = arrAvg( inputs, cnt );
	printf("The mean of you array is %lf\n", mean);

	return 0;
}
