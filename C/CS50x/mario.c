#include <stdio.h>

int main(){
  for (int i = 0; i < 4; i++){
    printf("?");
  }
  printf("\n");

  const int gridSize = 10;
  for(int i = 0; i<gridSize;i++){
    for(int i = 0; i<gridSize;i++){
      printf("#");
    }
    printf("\n");
  }
}
