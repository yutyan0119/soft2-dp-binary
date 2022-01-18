#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "search.h"
#include "util.h"

// main関数
// プログラム使用例: ./knapsack 10 20
//  10個の品物を設定し、キャパ20 でナップサック問題をとく

int main(int argc, char **argv) {
  /* 引数処理: ユーザ入力が正しくない場合は使い方を標準エラーに表示して終了 */
  if (argc != 3) {
    fprintf(stderr, "usage: %s <filename> <max capacity (double)>\n", argv[0]);
    exit(1);
  }

  const int W = load_int(argv[2]);
  assert(W >= 0.0);

  Itemset *items = load_itemset(argv[1]);
  int n = items->number;
  assert(n > 0);  // 0以下も抑止する
  printf("max capacity: W = %d, # of items: %d\n", W, n);
  print_itemset(items);

  // ソルバーで解く
  int total = solve(items, W);
  int total2 = solve2(items, W);
  // 表示する
  printf("----\nbest solution for 0-1 knapsack:\n");
  printf("value: %d\n", total);
  printf("----\nbest solution for knapsack:\n");
  printf("value: %d\n", total2);
  free_itemset(items);
  return 0;
}
