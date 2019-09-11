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
  printf("point(%d,%d)", p->x, p->y);
}


point_t make_point (int a, int b)
{
 point_t p = { .x = a, .y = b };
 return p;
}

void print_rect (rectangle_t *rec)

{

  point_t upp=(rec->upper_left);
  point_t low=(rec->lower_right);

  printf("rectangle(upper_left=");
  print_point(&upp);
  printf(", lower_right=");
  print_point(&low);
  printf(")\n");
  
}

rectangle_t  make_rect (int a, int b, int c, int d)

{
  point_t upper = make_point(a,b);
  point_t lower =make_point(c,d);
  rectangle_t r= {.upper_left=upper, .lower_right=lower};
  return r;
} 

int area_rect(rectangle_t *r)
{
  point_t upp=(r->upper_left);
  point_t low=(r->lower_right);
  int a = (upp.y);
  int b = (low.x);
  int area = a * b;
  return area;

}

int main()
 
{
  int a=1;
  int b=2;
  int c=3;
  int d=4;

  rectangle_t r=make_rect(a,b,c,d);
  print_rect(&r);
   
}

