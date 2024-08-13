#include <stdio.h>

int main(void) {
  char str[] = "Hell\0o World";

  printf("%s", str);
  printf("%c,%c,%c", str[0], str[1], str[2]);
}
