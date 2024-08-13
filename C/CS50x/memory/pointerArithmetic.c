#include <stdio.h>

typedef char *string;
int main() {
  string s = "hello";
  char *st = "thomas";

  for (int i = 0; i < 7; i++) {
    printf("%c\n", *(st + i));
  }
  printf("%p", st);

  for (int i = 0; i < 7; i++) {
    printf("%c\n", *&st[i]);
  }
  for (int i = 0; i < 7; i++) {
    printf("%p\n", &st[i]);
  }
}
