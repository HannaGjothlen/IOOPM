#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

typedef struct point point_t;

struct point
{
  int x;
  int y;
};

typedef struct rectangle rectangle_t;

struct rectangle
{
  point_t upper_left;
  point_t lower_right;
};

void translate(point_t *p1, point_t *p2)
{
  p1->x += p2->x;
  p1->y += p2->y;
}

void print_point (point_t *p)
{
  printf("point(%d,%d)\n", p->x, p->y);
}


point_t make_point (int a, int b)
{
 point_t p = { .x = a, .y = b };
 return p;
}

void print_rect (rectangle_t *p)
  
{
  print_point(&p);
  printf("rectangle(upper_left=(%d), lower_right=(%d)\n"), p->x, p->y);
}
  
int main()
 
{
  int c=1;
  int d=2;
  point_t p;
  p = make_point(c,d);
  print_point(&p);
}
