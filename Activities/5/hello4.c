#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *buff = NULL ;
   size_t len = 0 ;

   puts( "Please enter a float value => " ) ;
   getline( &buff, &len, stdin ) ;
 
   double number = atof(buff);

   printf( "%f\n", number ) ;

   free( buff ) ;
	return 0 ;
}
