#include <math.h>
#include <stdio.h>

int countLettersOfWord(char[]);
int avgLettersPrWord(char[]);
int avgNumOfSenteces(char[]);
int gradeText(char[]);
int main(void) {
  char word[] = "Hello world i am thomas";
  int count = avgLettersPrWord(word);
  printf("%i", count);
  return 1;
}

int countLettersOfWord(char word[]) {
  int count = 0;
  while (word[count] != '\0' && word[count] != ' ') {
    count++;
  }
  return count;
}

int avgLettersPrWord(char text[]) {
  int wordCount = 1;
  int lengthSum = 0;
  int n = 0;
  int wordStart = 0;
  while (text[n] != '\0') {
    if (text[n] == ' ') {
      lengthSum += countLettersOfWord(&text[wordStart]);
      wordStart = n + 1;
      wordCount++;
    }
    n++;
  }
  lengthSum += countLettersOfWord(&text[wordStart]);
  return round((float)lengthSum / wordCount * 100);
}

int avgNumOfSenteces(char text[]) {
  int wordCount = 1;
  int n = 0;
  int sentenceCount = 1;
  while (text[n] != '\0') {
    if (text[n] == ' ') {
      wordCount++;
    }
    if (text[n] == '.') {
      sentenceCount++;
    }
    n++;
  }
  return round((float)sentenceCount / wordCount * 100);
}

int gradeText(char text[]) {
  float index;
  index =
      0.0588 * avgLettersPrWord(text) - 0.296 * avgNumOfSenteces(text) - 15.8;
  return round(index);
}
