#include <stdio.h>

void int2string( int n, char answer[]) {
	char temp[11];
	size_t i = 0;		

	if (n == 0) {
		*(answer) = '0';
		i++;
	}
	while ( n > 0 ) {	
		*(temp+i) =  ((n % 10 ) + '0');	
		n /= 10;
		i++;
	}
	
	for (size_t c = i; c > 0; c--) {
		*(answer+(i-c)) = *(temp+c-1); 	
	}
	*(answer+i) = '\0';
}

int main() {
	char *in = NULL ;
	size_t len ;		
	int input;
	char answer[11];

	while( getline( &in, &len, stdin ) > 1 )
	{	
		sscanf( in, "%d", &input);	
		int2string( input, answer );
		printf("\n%s\n", answer);
	}
	
	return 0;
}
