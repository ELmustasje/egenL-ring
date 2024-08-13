#include <stdio.h>
#include <stdlib.h>

void mergesort(int arr[], int len);
void merge(int a[], int lenA, int b[], int lenB);
int main(void) {
  int arr[] = {1, 5, 6, 3, 4, 1, 3, 52, 523, 5, 325, 2};
  int a[] = {1, 3, 7, 8};
  int b[] = {2, 4, 5, 6};

  merge(a, 4, b, 4);
}

void mergesort(int arr[], int len) {
  if (len == 1) {
    return;
  }

  int middle = len / 2;
  int left = 0;
  int rigth = len - middle;
}

void merge(int a[], int lenA, int b[], int lenB) {
  int *temp = malloc(sizeof(int) * (lenA + lenB));
  int aIndex = 0;
  int bIndex = 0;

  int tempIndex = 0;
  while (tempIndex < lenA + lenB) {
    if (aIndex == (lenA)) {
      temp[tempIndex] = b[bIndex];
      bIndex++;
      tempIndex++;
    } else if (bIndex == (lenB)) {
      temp[tempIndex] = a[aIndex];
      aIndex++;
      tempIndex++;
    } else {
      if (a[aIndex] < b[bIndex]) {
        temp[tempIndex] = a[aIndex];
        aIndex++;
        tempIndex++;
      } else if (b[bIndex] <= a[aIndex]) {
        temp[tempIndex] = b[bIndex];
        bIndex++;
        tempIndex++;
      }
    }
    printf("tempIndex = %i\n aIndex = %i\n bIndex = %i\n valueAdded = %i\n",
           tempIndex - 1, aIndex, bIndex, temp[tempIndex - 1]);
  }
  for (int i = 0; i < lenA + lenB; i++) {
    printf("%i, ", temp[i]);
  }
}
