#include <stdio.h>
#include <stdlib.h>
// O(n^2)
void bubbleSort(int[], int);
int main(void) {
  long long t = 999999;
  int *arr = malloc(t * sizeof(int)); // Dynamically allocate memory

  for (long long i = 0; i < t; i++) {
    arr[i] = rand() % 5000;
  }
  bubbleSort(arr, t);
  free(arr); // Don't forget to free the allocated memory
  return 0;
}

void bubbleSort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - (i + 1); j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
