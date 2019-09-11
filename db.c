#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

typedef struct item item_t;

struct item
{
  char *name;
  char *desc;
  int price;
  char *shelf; 
};

  
void print_item(item_t *merch)
  {
    printf("Name: %s\n", merch -> name);
    printf("Desc: %s\n", merch -> desc);
    printf("Price: %d.%d\n", merch -> price, merch -> price%100);
    printf("Shelf: %s\n", merch -> shelf);
   
  }


item_t make_item(char *n, char *d, int p, char *s)

{
  item_t i =  {.name=n, .desc=d, .price=p, .shelf=s};
  return i;
}


bool is_shelf(char *shelf)

{
  if(isalpha(shelf[0]) && is_number(shelf+1))
    {
      return true;
    }
  else
      {
       return false;
      }
      
 }
	 


char *ask_question_shelf(char *question)

    {
      return ask_question(question, is_shelf, (convert_func) strdup).string_value;
    }

item_t input_item(void)

{

 char *name =ask_question_string("Name: ");
 char *desc = ask_question_string("Desc:");
 int price =  ask_question_int("Price:");
 char *shelf = ask_question_shelf("Shelf:");

 return make_item(name, desc, price, shelf);
}


int main()

{
  ask_question_shelf("heeeeeeej");
  return 0;
  
}
