#include <stdio.h>

void print(char *str)
{
  int count = 0;

  while (str[count] != '\0')
    {
      putchar(str[count]);
      count++;
    }
}

void println(char *str)
{
  int count = 0;

  while (str[count] != '\0')
    {
      putchar(str[count]);
      count++;
      
    }
  printf("\n");
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
      println(argv[1]);
    }
     
     
}
