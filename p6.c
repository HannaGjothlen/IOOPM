#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  
  for (n, n==m, 

    (n == m)
   {
     printf("gcd(%d, %d) = %d\n", n, m, n);
     n++;
   }
 

  while (n > m)
      {
        n = n - m;
        printf("gcd(%d, %d) = %d\n", n, m, n);
      }

     
   while (n < m)
      {
	 m = m - n;
	 printf("gcd(%d, %d) = %d\n", m, n, m);
      }

   return 0;

}
   
  
      
  
