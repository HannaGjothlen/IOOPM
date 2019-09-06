#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include <time.h>

int main(void)
{
  int buf_siz = 255;
  char buf[buf_siz];
  char *name = ask_question_string("Vad heter du?", buf, buf_siz);
  int number;

 
  int rand = random() % 1024;
  int count = 0;

  
  
  printf("Du %s, jag tänker på ett tal ", name);
  number = ask_question_int("kan du gissa vilket?");
  printf("mitt tal %d", number);
  printf("%d", rand);
 
  while (!(number == rand) && count < 15)
    {
       if (number > rand)
        {
          number = ask_question_int("För stort");
          count++;
        }
      else 
        {
          number = ask_question_int("För litet");
          count++;
        }
      
    }

  if (number == rand)
        {
          printf("Du gissade rätt, det tog %s %d gissningar att komma fram till %d.\n", name, count, rand);
        }
  else
    {
      printf("Du fick slut på gissningar. Talet var %d\n.", rand);
    }
    
    
  return 0;


}
