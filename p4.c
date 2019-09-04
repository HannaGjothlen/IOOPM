#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int num = atoi(argv[1]);

  int num2 = atoi(argv[2]);

  int count = 0;
  int y;
  int x;
  int w;
  for (x = 1 ; x<=num ; x++)        
  {                    
       
    for (y = 1; y <= (num2*x); y++)
      {
	printf("*");

	  
       count++;
      }
    printf("\n");
        
  }
  printf("Totalt: %d\n", (count));
  return 0;
}
