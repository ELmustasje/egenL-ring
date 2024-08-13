#include <math.h>
#include <stdio.h>

long long getNumber();
int calculateChecksum(long long);
int checkCarrier(long long);

int main() {
  long long cardNum = getNumber();
  if (calculateChecksum(cardNum) == 0) {
    return 0;
  };
  if (checkCarrier(cardNum) == 0) {
    return 0;
  }
  return 1;
}

long long getNumber() {
  long long number = 0;
  printf("ENTER YOUR CARD-NUMBER: ");
  scanf("%lld", &number);
  return number;
}

int calculateChecksum(long long number) {
  int checkSum = 0;
  int multiplyByTwo = -1;
  while (number > 0) {
    int digit = number % 10;
    if (multiplyByTwo == 1) {
      digit *= 2;
      if (digit / 10 == 0) {
        checkSum += digit % 10;
      } else {
        checkSum += digit % 10;
        checkSum += digit / 10;
      }
    } else {
      checkSum += digit;
    }
    multiplyByTwo = multiplyByTwo * -1;
    number = number / 10;
  }
  if (checkSum % 10 == 0) {
    return 1;
  }
  printf("INVALID\n");
  return 0;
}

int checkCarrier(long long number) {
  int count = 0;
  long long numberCopy = number;
  while (number > 0) {
    number = number / 10;
    count++;
  }
  numberCopy = numberCopy / pow(10, (count - 2));

  if (count == 15) {
    if (numberCopy == 34 || numberCopy == 37) {
      printf("AMEX\n");
      return 1;
    }
  }
  if (count == 16) {
    if (numberCopy == 51 || numberCopy == 52 || numberCopy == 53 ||
        numberCopy == 54 || numberCopy == 51) {
      printf("MASTERCARD\n");
      return 1;
    }
    if (numberCopy / 10 == 4) {
      printf("VISA\n");
      return 1;
    }
  }
  if (count == 13) {
    if (numberCopy / 10 == 4) {
      printf("VIST\n");
      return 1;
    }
  }
  printf("INVALID\n");
  return 0;
}
