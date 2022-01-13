#include <assert.h>  // for assert()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for memset()
#include <unistd.h>  // for sleep()

#include "city.h"
#include "gen_array.h"
#include "map.h"
#include "solve.h"

int main(int argc, char **argv) {
  // const による定数定義
  const int width = 70;
  const int height = 40;
  const int max_cities = 100;

  Map map = init_map(width, height);

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <city file> <first ansnum>\n", argv[0]);
    exit(1);
  }
  int n = 1;  //都市数
  City *city = load_cities(argv[1], &n);
  assert(n > 1 && n <= max_cities);  // さすがに都市数100は厳しいので
  int first_ans_num = atoi(argv[2]);
  if (first_ans_num <= 0) {
    printf("first ansnum is invalid.\n");
    exit(1);
  }
  // 町の初期配置を表示
  plot_cities(map, city, n, NULL);
  sleep(1);

  // 訪れる順序を記録する配列を設定
  int *route = (int *)calloc(n, sizeof(int));
  int *ans_route = (int *)calloc(n, sizeof(int));  //正解配列
  for (int i = 0; i < n; i++) {
    route[i] = i;      //とりまの初期解
    ans_route[i] = i;  //初期解が解だったとき対策
  }
  double d = solve(city, n, route, ans_route);
  for (int i = 0; i < first_ans_num - 1; i++) {
    int *tmp_ansroute = (int *)calloc(n, sizeof(int));
    mix_array(route, n, i);
    double k = solve(city, n, route, tmp_ansroute);
    if (k < d) {
      printf("更新%d/%d\n", i + 1, first_ans_num);
      route_copy(tmp_ansroute, ans_route, n);
      d = k;
    }
    free(tmp_ansroute);
  }

  plot_cities(map, city, n, ans_route);
  printf("total distance = %f\n", d);
  for (int i = 0; i < n; i++) {
    printf("%d -> ", ans_route[i]);
  }
  printf("%d\n", ans_route[0]);

  // 動的確保した環境ではfreeをする
  free(route);
  free(ans_route);
  free(city);

  return 0;
}
