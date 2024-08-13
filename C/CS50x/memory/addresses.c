#include <stdio.h>

//& - find address of variable
//* - derefernce, get the value of an adress.

int main(void) {
  int n = 50;
  printf("%p\n", &n);
}
