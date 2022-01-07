#include <stdio.h>

void my_pow(int base, int n, long* res, int* count);

int main() {
  int n = 30;
  int base = 2;
  long res;
  int count = 0;
  my_pow(base, n, &res, &count);
  printf("%ld, %d\n", res, count);
  return 0;
}

void my_pow(int base, int n, long* res, int* count) {
  // printf("%d\n",n);
  if (n == 1) {
    *res = base;
    return;
  }
  if (n == 2) {
    *res = base * base;
    (*count)++;
    return;
  }
  if (n % 2 == 0) {
    long tmp;
    my_pow(base, n / 2, &tmp, count);
    my_pow(tmp, 2, res, count);
    printf("%d**%d = %ld\n", base, n, *res);
    (*count)++;
  }
  if (n % 2 == 1) {
    long tmp;
    my_pow(base, n / 2, &tmp, count);
    my_pow(tmp, 2, res, count);
    *res *= base;
    printf("%d**%d = %ld\n", base, n, *res);
    (*count)++;
  }
}