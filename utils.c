#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"



answer_t ask_question(char *question, check_func check, convert_func convert)
{
  int buf_siz = 255;
  char buf[buf_siz];
 
  
  do
    {
      printf("%s\n", question);
      read_string(buf, buf_siz);
      
	}
  while (!(check(buf)));
  

  return convert(buf);   
}



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

/*

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

*/

int ask_question_int(char *question)
{
  answer_t answer = ask_question(question, is_number, (convert_func) atoi);
  return answer.int_value; // svaret som ett heltal
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
  while  (a !='\0' && a != '\n' && counter < (buf_siz -1));

  if (buf[counter] == '\n' || counter==buf_siz-1 )
    {
      buf[counter] = '\0';
   
    }
  if (counter == buf_siz-1)
    {
      clear_input_buffer();
	}
  return (counter);
}


bool not_empty(char *str)
{
  return strlen(str) > 0;
}


char *ask_question_string(char *question)
{
  return ask_question(question, not_empty, (convert_func) strdup).string_value;
}

/*
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

*/

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



