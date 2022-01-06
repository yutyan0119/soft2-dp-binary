#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union IntAndFloat {
  int ival;
  float fval;
};

int main() {
  char a[] = "Hello,World\n";
  union IntAndFloat target[4];
  int sum[4];  // floatに変換前の値が入る
  for (int i = 0; i < 4; i++) {
    sum[i] = 0;
  }
  for (int i = 0; i < strlen(a); i++) {
    int n = (int)i / 4;
    printf("%d\n", a[i] * (int)pow(2, 8 * (i % 4)));
    sum[n] += a[i] * (int)pow(2, 8 * (i % 4));
    printf("sum[%d] = %d\n", i / 4, sum[n]);
  }
  for (int i = 0; i < 4; i++) {
    target[i].ival = sum[i];
    printf("%d\n", target[i].ival);
  }
  for (int i = 0; i < 4; i++) {
    printf("%.200f\n", target[i].fval);
  }
  return 0;
}