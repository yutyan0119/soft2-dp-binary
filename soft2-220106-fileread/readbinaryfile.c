#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s filename\n", argv[0]);
    exit(1);
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    perror(argv[1]);
    exit(1);
  }

  size_t datasize = 0;
  fread(&datasize, sizeof(size_t), 1, fp);

  double *data = (double *)malloc(sizeof(double) * datasize);
  fread(data, sizeof(double), datasize, fp);
  fclose(fp);

  /* 表示部分 - 一旦コメントアウト */
  /*
    for (int i = 0 ; i < datasize ; i++){
    printf("%f\n",data[i]);
    }
  */
  free(data);
  return EXIT_SUCCESS;
}
