 #include <stdio.h>
 #include <string.h>

 int main()
  {
     char name[31] ;  // len(name) ≤ 30
	  strcpy(name, "hello");
     int num_masts = 2 ;
     double loa = 43.376458; // in feet

     // read name, num_masts, loa

     printf("%s has %d masts, and an overall length of %.0f ft.\n", name, num_masts, loa);

     return 0 ;
} 
