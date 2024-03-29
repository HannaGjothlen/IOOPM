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


void print_menu()
{
  printf("[L]ägga till en vara\n [T]a bort en vara\n[R]edigera en vara\n Ån[g]ra senaste ändringen\n Lista [h]ela varukatalogen\n [A]vsluta\n");

}

bool check(char *input)
{
  int n = strlen(input);
  if (n!=1)
    {
      return false;
   }
  char c =input[0];
  char *valid = "LlTtRrGgHhAa";
    for(int i=0; i< strlen(valid); i++)
    {
      if (c==valid[i])
	{
	  return true;
	}
      
    }  

  return false; 
}


answer_t convert_char(char *str)

{
  answer_t answer;
  answer.int_value = str[0];
  return answer;
}


char ask_question_menu()
  
{
    print_menu();
    char c =ask_question("Gör ett val: ", check, (convert_char)).int_value;
    return toupper(c);
    
 }


  

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



void add_item_to_db(item_t *db, int *s)
{

  if(*s < 16)
    {
      item_t item  = input_item();
      db[*s] = item;
      *s= *s+1;
    }
  else
    {
      printf("No\n");
      
    }
 

 return;
}


void list_db(item_t *items, int no_items)
{
  int i = 0;
  while (i < no_items)
    {
      
      printf("%d. ", i + 1);
      printf("%s\n", items[i].name);
      
      i++;
    }
}


void edit_db(item_t *items, int size)
{
  int input;


  do {
    input = ask_question_int("Vilken vara ska ändras? Ange siffra. ");
    
  }

  while (input > size || input < 1);
  
  int index = input - 1;
  print_item(&items[index]);
  items[index] = input_item();
}



void remove_item_from_db (item_t *item, int *size)

{
  int input;
  
 
     
  list_db(item, *size);

    do {
      input= ask_question_int("Vilken vara vill du radera?");
      
    }
    while (input > *size || input < 1);

    input--;
    

  while(input < *size)
    {
      
    item[input] = item[input + 1];
    input++;
  }
  
  *size=*size-1;
  return;
  
  
  
  
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
    


void event_loop(item_t *db, int *db_siz)
{
  while (true)
    {
      char c = ask_question_menu();

      if('L' == c)
        {
          add_item_to_db(db, db_siz);
        }
      if ('T' == c)
        {
          remove_item_from_db(db, db_siz);
        }
      if ('R' == c)
        {
          edit_db(db, *db_siz);
        }
      if ('G' == c)
        {
          printf("Not yet impkemented!");
        }
      if ('H' == c)
        {
          list_db(db, *db_siz);
        }
      if ('A' == c)
        {
          break;
        }
    }
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

    event_loop(db, &db_siz);
    
  }
  return 0;
}
