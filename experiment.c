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
  bool right_answ = false;

  do
    {
      printf("%s\n", question);
      read_string(buf, buf_siz);
      right_answ = check(buf); //kollar om type är rätt
    }
  while (!(right_answ));

  putchar('\n');
  return convert(buf);
}



int main(void)
{
  //atoi                     // har typen char * -> int
  // (convert_func) atoi      // har typen char * -> answer_t
 
  char *buf[255];
  int x = ask_question(buf, is_number, (convert_func)atoi.int_value);
  printf("%d\n", x)
 
  
  
    }
