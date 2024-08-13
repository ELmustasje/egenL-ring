#include <stdio.h>

int calculateScore(char[]);
void calculateWinner(int, int);
int calculateLetter(char);
int main(void) {
  // variables
  char p1Word[15];
  char p2Word[15];
  int score1;
  int score2;

  printf("Player 1: ");
  scanf("%s", p1Word);
  printf("Player 2: ");
  scanf("%s", p2Word);

  score1 = calculateScore(p1Word);
  score2 = calculateScore(p2Word);

  calculateWinner(score1, score2);
  return 1;
}

int calculateScore(char s[]) {
  int score = 0;
  int n = 0;
  while (1) {
    if (s[n] == '\0') {
      break;
    }
    score += calculateLetter(s[n]);
    n++;
  }
  return score;
}

void calculateWinner(int score1, int score2) {
  if (score1 == score2) {
    printf("TIE");
  } else if (score1 > score2) {
    printf("Player 1 wins");
  } else if (score1 < score2) {
    printf("Player 2 wins");
  }
}

int calculateLetter(char c) {
  if ((int)c > 91) {
    c += -32;
  }
  if ((int)c < 65 || (int)c > 90) {
    return 0;
  }
  return (int)c - 64;
}
