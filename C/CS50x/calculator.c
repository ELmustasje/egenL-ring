#include <stdio.h>

void calculate(int x, char opperator[], int y);

int main() {
  int x;
  int y;
  char opperator[1];

  printf("enter a number\n");
  scanf("%d", &x);

  printf("enter a opperator\n");
  scanf("%s", &opperator);

  printf("enter a number\n");
  scanf("%d", &y);

  calculate(x, opperator, y);
}

void calculate(int x, char opperator[], int y) {
  if (*opperator == *"+") {
    printf("%d\n", (x + y));
  } else if (*opperator == *"-") {
    printf("%d\n", (x - y));
  } else if (*opperator == *"/") {
    printf("%0.20f\n", ((float)x / (float)y));
  } else if (*opperator == *"*") {
    printf("%d\n", (x * y));
  }
}
