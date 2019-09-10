#include <stdio.h>

 void print(char *str)
{
  

  while (*str)
    {
      putchar(*str);
      ++str;
    }
  
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      printf("To few arguments\n");
    }
  else
    {
      print(argv[1]);
      printf("\n");
      
    }
     
     
}
