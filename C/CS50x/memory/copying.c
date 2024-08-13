#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "Hello World";
  int x;
  char *a = str;
  a[0] = 'a';

  printf("%s\n", str);
  printf("%s\n", a);

  char *copy = malloc(strlen(str) + 1);
  char *copy2 = malloc(strlen(str) + 1);
  for (int i = 0, n = strlen(str); i <= n; i++) {
    copy[i] = str[i];
  }
  strcpy(copy2, str);

  str[2] = 'G';
  printf("%s\n", str);
  printf("%s\n", copy);

  // need to free this memory
  free(copy);
  free(copy2);

  return 0;
}
