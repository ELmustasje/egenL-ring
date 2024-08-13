#include <stdio.h>

int main() {
  int scores[3];
  scores[0] = 73;
  scores[1] = 22;
  scores[2] = 100;

  printf("My avg score is: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
