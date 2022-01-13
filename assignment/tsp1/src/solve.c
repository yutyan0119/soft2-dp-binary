#include "solve.h"

#include <stdio.h>
#include <stdlib.h>

#include "city.h"
#include "map.h"

double solve(const City *city, int n, int *route, int *ans_route) {
  int is_change = 0;
  double ans = calc_score(city, n, route);  //初期スコア
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(i, j,route);  // routeのiとjを入れ替える。
      double sum = calc_score(city, n, route);
      if (sum < ans) {
        sum = ans;
        is_change = 1;
        route_copy(route, ans_route, n);  // ansにコピー
      }
    }
  }
  if (is_change) {
    // ans_routeをrouteにコピーして解が更新されなくなるまでやる。
    route_copy(ans_route, route, n);
    ans = solve(city, n, route, ans_route);
  }
  return ans;
}

double calc_score(const City *city, int n, int *route) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    const int c0 = route[i];
    const int c1 = route[(i + 1) % n];  // nは0に戻る
    sum += distance(city[c0], city[c1]);
  }
  return sum;
}

void swap(int i, int j, int *route) {
  int c1 = route[i];
  route[i] = route[j];
  route[j] = c1;
  return;
}

void route_copy(int *route, int *copied_route, int n) {
  for (int i = 0; i < n; i++) {
    copied_route[i] = route[i];
  }
  return;
}