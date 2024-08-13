#include <stdio.h>

int main() {
  int size;
  printf("Enter the size: ");
  scanf("%d", &size);
  if (size < 1) {
    return main();
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i + 1; j++) {
      printf("#");
    }
    printf(" ");
    for (int j = 0; j < i + 1; j++) {
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
