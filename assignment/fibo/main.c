#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void mul_matrix(long a[][2], long b[][2], long result[][2]);
void pow_matrix(long a[][2], long n, long result[][2]);

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
  long base_matrix[2][2] = {{1, 1}, {1, 0}};
  long result[2][2] = {{1, 0}, {0, 1}};
  pow_matrix(base_matrix, n - 1, result);
  printf("fibo[%d] = %ld\n", n, result[0][0]);
}

void mul_matrix(long a[][2], long b[][2], long result[][2]) {
  long tmp[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tmp[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        tmp[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      result[i][j] = tmp[i][j];
    }
  }
  return;
}

void pow_matrix(long a[][2], long n, long result[][2]) {
  if (n == 1) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        result[i][j] = a[i][j];
      }
    };
    return;
  }
  if (n == 2) {
    mul_matrix(a, a, result);
    return;
  }
  if (n % 2 == 0) {
    long tmp[2][2];
    pow_matrix(a, n / 2, tmp);
    pow_matrix(tmp, 2, result);
  }
  if (n % 2 == 1) {
    long tmp[2][2];
    pow_matrix(a, n / 2, tmp);
    pow_matrix(tmp, 2, result);
    mul_matrix(result, a, result);
  }
  return;
}