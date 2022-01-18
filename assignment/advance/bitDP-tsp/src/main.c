#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "city.h"
#include "solve.h"
#define max_num 20


int main(int argc, char *argv[]) {
  int citynum;
  City *cities = load_cities(argv[1], &citynum);
  assert(citynum <= max_num);
  double dist[citynum][citynum];
  for (int i = 0; i < citynum; i++) {
    for (int j = i; j < citynum; j++) {
      dist[i][j] = distance(cities[i], cities[j]);
      dist[j][i] = dist[i][j];
    }
  }

  double **dp = malloc(sizeof(double) * ((1 << max_num) + 1));
  double *dpin = malloc(sizeof(double) * ((1 << max_num) + 1) * max_num);
  for (int i = 0; i < (1 << max_num) + 1; i++) {
    dp[i] = dpin + (max_num * i);
  }

  for (int i = 0; i < 1 << citynum; i++) {
    for (int j = 0; j < citynum; j++) {
      dp[i][j] = -1;
    }
  }
  double ans = 1000000;
  for (int i = 0; i < citynum; i++) {
    if (ans > solve((1 << citynum) - 1, i, dp, citynum, dist)) {
      ans = solve((1 << citynum) - 1, i, dp, citynum, dist);
    }
  }
  printf("%f\n", ans);
}