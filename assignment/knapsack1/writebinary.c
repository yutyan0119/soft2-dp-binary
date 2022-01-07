#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *fp;
  fp = fopen("knapsack.dat", "wb");
  srand(time(NULL));
  int num = 10;
  double value[num];
  double weight[num];
  for (int i = 0; i < num; i++) {
    value[i] = (double)rand() / RAND_MAX * 20;
    weight[i] = (double)rand() / RAND_MAX * 20;
    printf("%f, %f\n", value[i], weight[i]);
  }
  fwrite(&num, sizeof(int), 1, fp);
  fwrite(value, sizeof(double), num, fp);
  fwrite(weight, sizeof(double), num, fp);
  fclose(fp);
  FILE *fp2;
  fp2 = fopen("knapsack.dat","rb");
  int a;
  fread(&a,sizeof(int),1,fp2);
  printf("%d\n",a);
  double value2[num];
  double weight2[num];
  fread(value2,sizeof(double),num,fp2);
  fread(weight2,sizeof(double),num,fp2);
    for (int i = 0; i < num; i++) {
    printf("%f, %f\n", value2[i], weight2[i]);
  }
  fclose(fp2);
  return 0;
}