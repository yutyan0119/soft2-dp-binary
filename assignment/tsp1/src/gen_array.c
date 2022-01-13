#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min_max_rand(int min_value, int max_value, int seed) {
  srand(seed);
  return min_value + (int)((double)rand() / RAND_MAX * (max_value - min_value));
}

void mix_array(int* array, int n, int seed) {
  for (int i = 0; i < n; i++) {
    int p = min_max_rand(i, n, seed);
    int tmp = array[p];
    array[p] = array[i];
    array[i] = tmp;
  }
}