#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *in = NULL ;
	size_t len ;
	float floats[100] ;
	size_t cnt = 0;

	while( getline( &in, &len, stdin ) > 1 )
	{
		++cnt;
		sscanf( in, "%f", &floats[cnt-1]);
	}

	float rev[cnt] ;

	for (size_t i = cnt; i > 0; i--) {
		rev[cnt-i] = floats[i-1];
	}

	free( in ) ;
	return 0 ;
}
