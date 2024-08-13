#include <stdio.h>

void swap(int *a, int *b);
int main(void) {
  int a = 10;
  int b = 5;

  swap(&a, &b);
  printf("a is: %i, b is: %i", a, b);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
