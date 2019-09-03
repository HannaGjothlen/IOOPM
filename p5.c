#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 
int main(int argc, char *argv[])
{
  int n = atoi(argv[1]), c = 2;
   
   for ( c = 2 ; c <= n - 1 ; c++ )
   {
      if ( n%c == 0 )
      {
         printf("%d isn't prime.\n", n);
     break;
      }
   }
   if ( c == n )
      printf("%d is prime.\n", n);

   if (n == 1)
     printf("%d is not prime.\n", n);
       
   return 0;
}
