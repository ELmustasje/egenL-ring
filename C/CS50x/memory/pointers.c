#include <stdio.h>
// pointers is really just an adress
// syntax for pointer is type *name
int main(void) {
  int n = 50;
  int **p;
  int *pointer = &n;
  p = &pointer;
  printf("%p is the address of pointer pointing to n\n", pointer);
  printf("%i is the value of the pointer\n", *pointer);
  printf("%p is the addres of p pointing to pointer witch is pointing n\n", p);
}
