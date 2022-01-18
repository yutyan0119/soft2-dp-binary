#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *fp;
  fp = fopen("knapsack.dat", "wb");
  srand(time(NULL));
  int num = 10;
  int value[num];
  int weight[num];
  for (int i = 0; i < num; i++) {
    value[i] = 1 + (double)rand() / RAND_MAX * 19;
    weight[i] = 1 + (double)rand() / RAND_MAX * 19;
    printf("%d, %d\n", value[i], weight[i]);
  }
  fwrite(&num, sizeof(int), 1, fp);
  fwrite(value, sizeof(int), num, fp);
  fwrite(weight, sizeof(int), num, fp);
  fclose(fp);
  FILE *fp2;
  fp2 = fopen("knapsack.dat", "rb");
  int a;
  fread(&a, sizeof(int), 1, fp2);
  printf("%d\n", a);
  int value2[num];
  int weight2[num];
  fread(value2, sizeof(int), num, fp2);
  fread(weight2, sizeof(int), num, fp2);
  for (int i = 0; i < num; i++) {
    printf("%d, %d\n", value2[i], weight2[i]);
  }
  fclose(fp2);
  return 0;
}