#include <stdio.h>

int z;
extern int b;//is global in main 
//extern int c;//is static in main

void func(int a, int c)
{
  register int *x = NULL;
  x = (int*) &func;
  ((void(*)())x)();
  printf("func: a: %d, b: %d, c: %d, z: %d\n", a, b, c, z);
}

