#include <stdio.h>
int main() {
  int arr[] = {1, 12, 44, 222, 275, 2355, 4066, 23677};
  int size = 8;
  int timeCount = 1;
  // worst case is finding the last element.
  int target = 23677;

  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      printf("%i", timeCount);
      return 1;
    }
    timeCount++;
  }
  return 0;
}
