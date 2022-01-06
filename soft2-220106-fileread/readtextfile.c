#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    perror(argv[1]);
    return EXIT_FAILURE;
  }

  size_t size = 0;
  char buf[256];

  // サイズ情報の読み取り
  fgets(buf, 256, fp);
  sscanf(buf, "%zu%*[\n]", &size);

  // 読み取ったサイズ情報に基づいてmalloc
  double *data = (double *)malloc(sizeof(double) * size);
  size_t i = 0;

  // 1行ずつ読み取って値をセット
  while (fgets(buf, 256, fp) != NULL) {
    sscanf(buf, "%lf%*[\n]", data + i++);
  }

  fclose(fp);
  free(data);

  return EXIT_SUCCESS;
}
