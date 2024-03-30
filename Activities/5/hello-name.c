#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *buff = NULL ;
	size_t len = 0 ;
   char name[41] ;

   puts( "Please enter your name => " ) ;
   getline( &buff, &len, stdin ) ;

   strncpy( name, buff, 40 ) ;
   name[40] = '\0' ;   // Just in case strncpy didn't find '\0'

   printf( "Hello, %s!\n", name ) ;

   free( buff ) ;
   return 0 ;
} 
