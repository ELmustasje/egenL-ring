#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  int number;
} person;

int main(void) {
  person people[3];
  people[0].id = 0;
  people[0].number = 48456975;
  people[1].id = 1;
  people[1].number = 1257831;
  people[2].id = 2;
  people[2].number = 74975377;
  return 0;
}
