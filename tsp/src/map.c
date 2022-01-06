#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memset, strlen
#include "city.h"
#include "map.h"

// 整数最大値をとる関数
static int max(const int a, const int b)
{
  return (a > b) ? a : b;
}

Map init_map(const int width, const int height)
{
    char **dot = (char**) malloc(width * sizeof(char*));
    char *tmp = (char*)malloc(width*height*sizeof(char));
    for (int i = 0 ; i < width ; i++)
	dot[i] = tmp + i * height;
    return (Map){.width = width, .height = height, .dot = dot};
}

void free_map_dot(Map m)
{
    free(m.dot[0]);
    free(m.dot);
}

// 繋がっている都市間に線を引く
void draw_line(Map map, City a, City b)
{
    const int n = max(abs(a.x - b.x), abs(a.y - b.y));
    for (int i = 1 ; i <= n ; i++){
	const int x = a.x + i * (b.x - a.x) / n;
	const int y = a.y + i * (b.y - a.y) / n;
	if (map.dot[x][y] == ' ') map.dot[x][y] = '*';
    }
}

void draw_route(Map map, City *city, int n, const int *route)
{
    if (route == NULL) return;
    
    for (int i = 0; i < n; i++) {
	const int c0 = route[i];
	const int c1 = route[(i+1)%n];// n は 0に戻る必要あり
	draw_line(map, city[c0], city[c1]);
    }
}

void plot_cities(Map map, City *city, int n, const int *route)
{
    printf("----------\n");

    memset(map.dot[0], ' ', map.width * map.height); 
    
    // 町のみ番号付きでプロットする
    for (int i = 0; i < n; i++) {
	char buf[100];
	sprintf(buf, "C_%d", i);
	for (int j = 0; j < strlen(buf); j++) {
	    const int x = city[i].x + j;
	    const int y = city[i].y;
	    if (x < map.width)
		map.dot[x][y] = buf[j];
	}
    }

    draw_route(map, city, n, route);
    
    for (int y = 0; y < map.height; y++) {
	for (int x = 0; x < map.width; x++) {
	    const char c = map.dot[x][y];
	    putchar(c);
		}
	putchar('\n');
    }
    fflush(stdout);
}
