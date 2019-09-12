#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include <time.h>

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


void list_db(item_t *items, int no_items)
{
  int i = 0;
  while (i < no_items)
    {
      //char* item_name =(item -> name);
      printf("%d. ", i + 1);
      printf("%s\n", items[i].name);
      
      i++;
    }
}


void edit_db(item_t *items, int size)
{
  int input;


  do {
    input = ask_question_int("Vilken ska ändras? Ange siffra. ");
    
  }

  while (input > size || input < 1);
  
  int index = input - 1;
  print_item(&items[input]);
  items[index] = input_item();
}


char *magick(char *array_1[], char *array_2[], char *array_3[], int siz)
{
  char buf[255];
  char *word_1 = array_1[rand() % siz];
  char *word_2 = array_2[rand() % siz];
  char *word_3 = array_3[rand() % siz];

  int counter = 0;
  int end =  strlen(word_1);
  for(; counter <  end ; counter++)
    {
      buf[counter] = *word_1;
      word_1++;
    }
  buf[counter++]= '-';
  end += strlen(word_2)+1;

  for(; counter < end ; counter++)
    {
      buf[counter] = *word_2;
      word_2++;
    }
  buf[counter++]= ' ';

  end += strlen(word_3)+1;
  for(; counter < end ; counter++)
    {
      buf[counter] = *word_3;
      word_3++;
    }
  buf[counter++]= '\0';
  return strdup(buf);

}
    
 
 



int main(int argc, char *argv[])
{
  srandom(time(NULL));
  
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

    list_db(db, db_siz);
    edit_db(db, db_siz);
    list_db(db, db_siz);
    
  }
  return 0;
}
