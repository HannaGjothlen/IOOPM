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
 
  char *name = ask_question_string("Vad heter du?");
  int number;

  srandom(time(NULL));
  int rand = random() % 1024;
  int count = 0;

  
  
  printf("Du %s, jag tänker på ett tal ", name);
  number = ask_question_int("kan du gissa vilket?");
  
 
  while (!(number == rand) && count < 15)
    {
      if (number > rand)
        {
          count++;
          number = ask_question_int("För stort");
          
        }

      else 
        {
          count++;
          number = ask_question_int("För litet");
          
        }
      
    }

  if (number == rand)
        {
          count++;
          printf("Du gissade rätt, det tog %s %d gissningar att komma fram till %d.\n", name, count, rand);
         
        }
  else
    {
      printf("Du fick slut på gissningar. Talet var %d\n.", rand);
    }
    
    
  return 0;


}
