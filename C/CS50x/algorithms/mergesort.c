#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, long long len);
void merge(int *arr, long long l, long long m, long long r);

int main(void) {
  long long t = 999999;
  int *arr = malloc(t * sizeof(int)); // Dynamically allocate memory

  for (long long i = 0; i < t; i++) {
    arr[i] = rand() % 5000;
  }
  mergeSort(arr, t);
  free(arr); // Don't forget to free the allocated memory
  return 0;
}

void mergeSort(int *arr, long long len) {
  if (len < 2) {
    return;
  }
  long long mid = len / 2;

  mergeSort(arr, mid);
  mergeSort(arr + mid, len - mid);
  merge(arr, 0, mid, len);
}

void merge(int *arr, long long l, long long m, long long r) {
  long long n1 = m - l;
  long long n2 = r - m;
  int *lArr = malloc(n1 * sizeof(int));
  int *rArr = malloc(n2 * sizeof(int));

  if (lArr == NULL || rArr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    free(lArr);
    free(rArr);
    return;
  }

  for (long long i = 0; i < n1; i++) {
    lArr[i] = arr[l + i];
  }
  for (long long i = 0; i < n2; i++) {
    rArr[i] = arr[m + i];
  }

  long long i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (lArr[i] <= rArr[j]) {
      arr[k] = lArr[i];
      i++;
    } else {
      arr[k] = rArr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = lArr[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rArr[j];
    j++;
    k++;
  }

  free(lArr);
  free(rArr);
}
