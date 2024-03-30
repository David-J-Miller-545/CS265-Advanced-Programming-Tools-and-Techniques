#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *in = NULL ;
	size_t len ;	
	size_t cnt = 0;
	double max;
	double min;
	double current;
	double mean = 0;	

	while( getline( &in, &len, stdin ) > 1 )
	{
		++cnt;
		if (cnt == 1) {
			sscanf (in, "%lf", &max);
			sscanf (in, "%lf", &min);
		}
		sscanf( in, "%lf", &current);
		max = (current > max) ? current : max;
		min = (current < min) ? current : min;
		mean += current;
	}
	mean /= cnt;	

	printf( "\nMax: %f\nMin: %f\nMean: %f\n", max, min, mean ) ;

	free( in ) ;
	return 0 ;
}
