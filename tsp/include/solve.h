#pragma once
#include "city.h"

double solve(const City *city, int n, int *route, int *ans_route);

double calc_score(const City *city, int n, int *route);

void swap(int i, int j, int *route);

void route_copy(int *route, int *copied_route, int n);