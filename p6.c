#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool is_number(char *str)
{
  int n = strlen(str);

  
  for(int i=0; i<n; i++)
    {
      if (str[i]=='-'&& i==0 && n>1)
	{
	  continue;
	}
      if (isdigit(str[i]))
	{
       
	}
     
      else
	{
	  return false;
	}
    }
  return true;
}



int main(int argc, char *argv[])
{
		
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  int a = n;
  int b = m;
  while (is_number(argv[1]) && is_number(argv[2])&& n>=0 && m>=0)
    {
      if (  n!=m)
    {
 	 	
      if (n>m)
	{
	  n = n - m;
	  
	}

      else if  (n < m)
	{
	  m = m - n;
        
	}
    
   }
  printf("gcd(%d, %d) = %d\n", a, b, n);
  return 0;
  }
   printf("error\n");
  return 0;   
}

  
      
  
