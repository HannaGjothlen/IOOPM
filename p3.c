#include <stdio.h>

int main(void)
{
  int i;
  int a;
  int x = 0;
  for (i = 1; i <= 10; i++)        
  {                    
       
    for (a = 1; a <= i; a++)
      {
	printf("*");
        
        x++;
      }
    printf("\n");
        
  }
  printf("Totalt: %d\n", (x));
  return 0;
}
