#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



int m;
void print_number(int m)
{
  if (m%5 == 0 && m%3 == 0)
    {
      printf("Fizz Buzz ");  
    }
  
  else if (m%5==0)
    {
     printf("Buzz ");
    }
  else if (m%3==0)
    {
      printf("Fizz ");
    }  
  else
    {
      printf("%d ", m);
    }
}
	
   
  
int main(int argc, char *argv[])

{
  int n = atoi(argv[1]);

  for (int i=1; i<=n; i++)   
    {
      print_number(i);
      if (i<n)
	{
	  printf(", ");
	}
    }
  printf("\n");
  return 0;
}
