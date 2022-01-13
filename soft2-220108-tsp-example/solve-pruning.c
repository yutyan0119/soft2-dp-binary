#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "city.h"
#include "map.h"
#include "solve.h"

double solve(const City *city, int n, int *route, int *visited) {
  route[0] = 0;  // 循環した結果を避けるため、常に0番目からスタート
  visited[0] = 1; //0は訪れたことにする

  Answer ans = search(city, n, route, visited);

  memcpy(route, ans.route, sizeof(int) * n);
  free(ans.route);
  return ans.dist;
}

Answer search(const City *city, int n, int *route, int *visited) {
  static double mindis = 10000000000;
  int start = 0;
  double cum_dis = 0;
  // 訪問した個数および訪問したところまでの累積距離を計算
  int c0 = route[0];
  for (int i = 1; i < n; i++) {
    if (!route[i]) {//i番目が埋まってない
      start = i;//i番目をスタートにする
      break;
    } else {
      int c1 = route[i];
      cum_dis += distance(city[c0], city[c1]);
      c0 = c1;
    }
  }

  // 全て訪問したケース（ここが再帰の終端条件）
  if (start == 0) {
    // 個数カウント時に距離計算しているので簡略化可能
    double sum_d = cum_dis + distance(city[c0], city[0]);
    int *retarg = (int *)malloc(sizeof(int) * n);
    memcpy(retarg, route, sizeof(int) * n);
    if (sum_d < mindis) mindis = sum_d;
    return (Answer){.dist = sum_d, .route = retarg};
  }

  // 特定の分岐における最小の巡回経路を調べる
  Answer min = {.dist = 10000000000, .route = NULL};
  for (int i = 1; i < n; i++) {
    // 未訪問なら訪れる
    if (!visited[i]) { //iという場所を訪れてないならそこを今回訪れる場所にする。
      if (i == 2 && !visited[1]) continue;  // 逆順の巡回経路を抑制<-what? 2を訪れていなくて、かつ1を訪れていない?

      // ここまでの累積距離が現状の最小距離を超えていたら枝刈り
      if (cum_dis + distance(city[route[start - 1]], city[i]) > mindis)
        continue;

      route[start] = i; //未探索のindexを埋める
      visited[i] = 1; //訪れたよ

      Answer tmp = search(city, n, route, visited); //再帰する

      // 最小の巡回経路かどうか確認
      if (tmp.dist < min.dist) {
        free(min.route);
        min = tmp;
      } else {
        free(tmp.route);
      }

      route[start] = 0;
      visited[i] = 0;
    }
  }

  return min;
}
