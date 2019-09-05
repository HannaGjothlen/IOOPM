#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int main(int argc, char *argv[])
{
  char* name;
  int* number;
  printf("Enter your name:\n");
  scanf("%s", name);
  printf("Du %s, jag tänker på ett tal ... kan du gissa vilket?\n", name);
  scanf("%dl", number);


  int random_num =random() % 1024;
  


}
