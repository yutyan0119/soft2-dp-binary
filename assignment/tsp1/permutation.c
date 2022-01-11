#include <stdio.h>
#include <stdlib.h>

void next_permutation(int data[], int index, int used[], int length);

int main() {
  int n = 5;
  int used[n];
  for (int i = 0; i < n; i++) {
    used[i] = -1;
  }
  used[0] = 1;
  int data[n];
  data[0] = 0;
  next_permutation(data, 1, used, n);
  return 0;
}

void next_permutation(int data[], int index, int used[], int length) {
  if (index == length) {
    for (int i = 0; i < length; i++) {
      printf("%d ", data[i]);
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < length; i++) {
    if (used[i] == -1) {
      data[index] = i;
      used[i] = 1;
      next_permutation(data, index + 1, used, length);
      used[i] = -1;
    }
  }
}