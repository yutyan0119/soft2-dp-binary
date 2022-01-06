#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int** mul_matrix(int a[][2], int b[][2]);
int** pow_matrix(int a[][2], int n);

int main(int argc, char** argv) {
  if (argc < 2 || argc > 3) {
    fprintf(stderr, "execute like %s number\n", argv[0]);
    return EXIT_FAILURE;
  }
  char* e;
  int n = (int)strtol(argv[1], &e, 10);
  if (*e != '\0') {
    fprintf(stderr, "invalid argument\n");
    return EXIT_FAILURE;
  }
  assert(n <= 90);
  int base_matrix[2][2] = {{1, 1}, {1, 0}};
  int** res = pow_matrix(base_matrix, n);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d", res[i][j]);
    }
    printf("\n");
  }
}

int** mul_matrix(int a[][2], int b[][2]) {
  int** result = malloc(sizeof(int*) * 2);
  int* in = malloc(sizeof(int) * 4);
  result[0] = in;
  result[1] = in + 2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      result[i][j] = 0;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return result;
}

int** pow_matrix(int a[][2], int n) {
  int** result = malloc(sizeof(int*) * 2);
  int* in = malloc(sizeof(int) * 4);
  result[0] = in;
  result[1] = in + 2;
  result[0][0] = 1;
  result[0][1] = 0;
  result[1][0] = 0;
  result[1][1] = 1;
  while (n > 0) {
    if (n & 1) {
      mul_matrix(result, a);
    }
    a = mul_matrix(a, a);
    n >>= 1;
  }
  return result;
}