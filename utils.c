#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int clear_input_buffer()
{
  int c;
     do
        {
          c = getchar();
        }
      while (c != '\n' && c != EOF);
      putchar('\n');
      return 0;
}

int ask_question_int(char *question)
{

  int result = 0;
  int conversions = 0;
  do
    {
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      clear_input_buffer();
    }
  while (conversions < 1);
  return result;
}


int read_string(char *buf, int buf_siz)
{
  int counter = 0;
  int a;
  do
    {
      a = getchar();
      buf[counter] = a;
      counter++;
      
    }
  while  (a !='\0' && a != '\n' && counter <= (buf_siz -1));

  if (buf[counter-1] == '\n')
    {
      buf[counter-1] = '\0';
    
    }
 
  return (counter-1);
}


char *ask_question_string(char *question, char *buf, int buf_siz)
{
  int chars=0;
  do
    {
     printf("%s\n", question);
     chars= read_string(buf, buf_siz);       
    }
  while (chars < 1);
  return strdup(buf) ;
}

  void print(char *str)
{
  
  int i = 0;
 
while (str[i] != '\0')
  {
    putchar(str[i]);
    i++;
  }
}



void printl(char *str)
{
   
     print(str);
     print("\n");
    
}


