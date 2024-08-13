#include <stdio.h>
#include <string.h>

int main(void) {
  char *i;
  char *j;

  printf("word1: ");
  scanf("%s", i);
  printf("word1: ");
  scanf("%s", j);

  if (strcmp(j, i) == 0) {
    printf("same");
  } else {
    printf("different");
  }
}
