#include <stdio.h>

int main(void) {
  const int N = 3;
  int myNumbers[N];
  float avg = 0;
  for (int i = 0; i < N; i++) {
    scanf("%i", &myNumbers[i]);
    avg += myNumbers[i] / (float)N;
  }
  printf("%f\n", avg);
  printf("%i", myNumbers[5]);
}
