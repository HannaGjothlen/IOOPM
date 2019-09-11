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



char *magick(char array_1[], char array_2[], char array_3[])
  char buf[255];


 int rand = random() % 3;
//ev. lägga in varje karatär i buffern via loop.
//kanske använda strcat

/*
int main()

{
  ask_question_shelf("heeeeeeej");
  return 0;
 
}
*/ 

int main(int argc, char *argv[])
{
  char *array1[] = {"Laser", "Polka","Extra" }; // TODO: Lägg till!
  char *array2[] = { "förnicklad","smakande", "ordinär" }; // TODO: Lägg till!
  char *array3[] = { "skruvdragare", "kola", "uppgift" }; // TODO: Lägg till!

  if (argc < 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0; // Antalet varor i arrayen just nu

    int items = atoi(argv[1]); // Antalet varor som skall skapas

    if (items > 0 && items <= 16)
    {
      for (int i = 0; i < items; ++i)
      {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item;
        ++db_siz;
      }
    }
    else
    {
      puts("Sorry, must have [1-16] items in database.");
      return 1; // Avslutar programmet!
    }

    for (int i = db_siz; i < 16; ++i)
      {
        char *name = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        char *desc = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        int price = random() % 200000;
        char shelf[] = { random() % ('Z'-'A') + 'A',
                         random() % 10 + '0',
                         random() % 10 + '0',
                         '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item;
        ++db_siz;
      }

     // Skriv ut innehållet
     for (int i = 0; i < db_siz; ++i)
     {
       print_item(&db[i]);
     }

  }
  return 0;
}
