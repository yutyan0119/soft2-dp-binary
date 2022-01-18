#include "search.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"

// ソルバーは search を index = 0 で呼び出すだけ
int solve(const Itemset *list, int capacity) {
  int n = list->number;
  // dp[i][j] 0~i番目までのアイテムを使ってjg以下に抑えたときの最高価値
  int dp[n + 1][capacity + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < capacity + 1; j++) {
      dp[i][j] = 0;  //初期化
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= capacity; j++) {
      dp[i + 1][j] = dp[i][j];  //まずは普通に前までのやつで更新
      if (j - list->item[i].weight >= 0) {
        //加えるときの判定をして加える
        if (dp[i][j - list->item[i].weight] + list->item[i].value >
            dp[i + 1][j]) {
          dp[i + 1][j] = dp[i][j - list->item[i].weight] + list->item[i].value;
        }
      }
    }
  }

  return dp[n][capacity];
}

int solve2(const Itemset *list, int capacity) {
  int n = list->number;
  // dp[i][j] 0~i-1までのアイテムを使ってjg以下に抑えたときの最高価値
  int dp[n + 1][capacity + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < capacity + 1; j++) {
      dp[i][j] = 0;  //初期化
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= capacity; j++) {
      dp[i + 1][j] = dp[i][j];  //まずは普通に前までのやつで更新
      if (j - list->item[i].weight >= 0) {
        //加えるときの判定をして加える
        if (dp[i][j - list->item[i].weight] + list->item[i].value >
            dp[i + 1][j]) {
          dp[i + 1][j] = dp[i][j - list->item[i].weight] + list->item[i].value;
        }
        //同じのを繰り返し使うとき
        if (dp[i + 1][j - list->item[i].weight] + list->item[i].value >
            dp[i + 1][j]) {
          dp[i + 1][j] =
              dp[i + 1][j - list->item[i].weight] + list->item[i].value;
        }
      }
    }
  }
  return dp[n][capacity];
}