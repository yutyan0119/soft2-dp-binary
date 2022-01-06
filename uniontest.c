#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union IntAndFloat {
  int ival;
  float fval;
};

int main() {
  char a[] = "Hello, World\n";
  char** num = malloc(sizeof(char*) * 4);
  char* string = malloc(sizeof(char) * 64 * 4);
  for (int i = 0; i < 4; i++) {
    num[i] = (string + 64 * i);
  }
  
  for (int i = 0; i < strlen(a); i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i] & 1 << 7 - j) {
        printf("%d", 1);
      } else {
        printf("%d", 0);
      }
    }
    printf("\n");
  }
  int i = 0;
  union IntAndFloat target;
  target.ival = 0b00000000000000000000000000001010;

  printf("target = %g\n", target.fval);
  for (i = 0; i < 32; i++) {
    if ((target.ival & 0x80000000) == 0x80000000) {
      printf("1");
    } else {
      printf("0");
    }
    target.ival = target.ival << 1;
  }
  printf("\n");
  free(string);
  free(num);
  return 0;
}