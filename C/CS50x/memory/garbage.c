#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a = malloc(100);
  *a = 10;
  for (int i = 0; i < 100; i++) {
    printf("%i\n", a[i]);
  }

  int b[100] = {20};
  for (int i = 0; i < 100; i++) {
    printf("%i\n", b[i]);
  }
}
