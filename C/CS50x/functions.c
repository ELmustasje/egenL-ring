#include <stdio.h>

void meow();

int main(){
  for (int i = 0; i < 3; i++) {
    meow();
  }
}

void meow(){
  printf("meow\n");
}


