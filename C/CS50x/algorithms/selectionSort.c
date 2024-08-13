#include <stdio.h>
#include <stdlib.h>

void selectionSort(int[], int);
int main(void) {
  int arr[99999999999];
  for (int i = 0; i < 30000; i++) {
    arr[i] = rand() % 5000;
  }
  int len = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, len);
}
void selectionSort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    int currentNum = arr[i];
    int index = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < currentNum) {
        currentNum = arr[j];
        index = j;
      }
    }
    int temp = arr[i];
    arr[i] = currentNum;
    arr[index] = temp;
  }
}
