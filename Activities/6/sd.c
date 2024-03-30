#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *in = NULL ;
	size_t len ;
	float floats[100] ;
	size_t cnt = 0;
	float mean = 0;
	float sd = 0;

	while( getline( &in, &len, stdin ) > 1 )
	{
		++cnt;
		sscanf( in, "%f", &floats[cnt-1]);
	}

	for (size_t i = 0; i < cnt; i++) {
		mean += floats[i];
	}
	mean /= cnt;

	for (size_t i = 0; i < cnt; i++) {
		float temp = (powf((floats[i] - mean), 2.));
		sd += temp;
	}
	sd /= cnt;
	sd = sqrtf(sd);

	printf( "\nMean: %f\nStandard Deviation: %f\n", mean, sd ) ;

	free( in ) ;
	return 0 ;
}
