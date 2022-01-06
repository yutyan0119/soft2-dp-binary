#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s filename\n", argv[0]);
    return EXIT_FAILURE;
  }
  FILE *fp;
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    // fopen は失敗した場合 errno の変数をセットする
    // perror は errno の番号に対応したメッセージを返してくれる
    perror(argv[1]);
    return EXIT_FAILURE;
  }
  // 100バイトのchar配列（スタック領域）
  char buf[100];

  // 1バイトを100個分読み出す。rsize には読み出した個数が格納される
  size_t rsize = fread(buf, sizeof(char), 100, fp);

  printf("%zu Byte read\n", rsize);

  // 文字列だと解釈したい場合は終端記号\0を追加
  // この作業は必須ではない（場合によってはrsizeがbufをはみ出すことに注意）
  if (rsize < 100) {
    buf[rsize] = '\0';
    printf("%s", buf);
  }
  return EXIT_SUCCESS;
}