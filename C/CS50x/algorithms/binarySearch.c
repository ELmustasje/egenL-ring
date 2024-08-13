#include <stdio.h>
int binarySearch(int[], int, int, int, int);
int binarySearch2(int[], int, int, int, int);
int main() {
  int arr[] = {1, 12, 44, 222, 275, 2355, 4066, 23677};
  int size = 8;
  int timeCount = 1;
  int target = 4066;
  binarySearch2(arr, target, 0, size, timeCount);
  return 0;
}

// recursion
int binarySearch(int arr[], int target, int start, int end, int timeCount) {
  int middleIndex = (start + end) / 2;
  printf("start: %i, end: %i\n", start, end);
  if (arr[middleIndex] == target) {
    printf("%i\n", timeCount);
    return 1;
  }
  if (start > end) {
    return -1;
  }
  if (arr[middleIndex] > target) {
    return binarySearch(arr, target, start, middleIndex - 1, timeCount + 1);
  }
  if (arr[middleIndex] < target) {
    return binarySearch(arr, target, middleIndex + 1, end, timeCount + 1);
  }
  return -2;
}

// loops
int binarySearch2(int arr[], int target, int start, int end, int timeCount) {
  while (start <= end) {
    int middle = (start + end) / 2;

    if (arr[middle] == target) {
      printf("%i", middle);
      return middle;
    }
    if (arr[middle] < target) {
      start = middle + 1;
    }
    if (arr[middle] > target) {
      end = middle - 1;
    }
  }
  return -1;
}
