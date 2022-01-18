#include "solve.h"

#include <stdio.h>
#include <stdlib.h>


double solve(int bit, int last_city, double **dp, int citynum,
             double dist[][citynum]) {
  if (dp[bit][last_city] != -1) {
    return dp[bit][last_city];
  }

  if (bit == (1 << last_city)) {
    return dp[bit][last_city] = 0;  //初期値
  }

  double res = __INT32_MAX__;

  int prev_bit = bit & ~(1 << last_city);
  for (int i = 0; i < citynum; i++) {
    if (!(prev_bit & (1 << i))) continue;

    if (res > solve(prev_bit, i, dp, citynum, dist) + dist[i][last_city]) {
      res = solve(prev_bit, i, dp, citynum, dist) + dist[i][last_city];
    }
  }

  return dp[bit][last_city] = res;
}