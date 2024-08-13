#include <stdint.h>
#include <stdio.h>

typedef char *string;
int main(void) {
  string a = "thomas";
  printf("%s\n", a);
  char *s = "test";
  printf("%s\n", s);
  char string[] = "hello\0 world";
  printf("%p\n", string);
  printf("%p\n", &string[0]);
  printf("%p\n", &string[1]);
  printf("%p\n", &string[2]);
  printf("%p\n", &string[3]);
  printf("%p\n", &string[4]);
}
