#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

string ary[5];
bool visited[29][29] = { false, };
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
double p[4], res = 0;
int n, in;

void dfs(int x, int y, int fcnt, double pi) {
	if (visited[y][x]) {
		res += pi;
		return;
	}
	if (fcnt == n) return;
	visited[y][x] = true;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		if (p[i] > 0) {
			nx = x + dir[i][1];
			ny = y + dir[i][0];
			dfs(nx, ny, fcnt + 1, pi * p[i]);
		}
	}
	visited[y][x] = false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &in);
		p[i] = in / 100.;
	}
	dfs(14, 14, 0, 1);
	printf("%.10lf", 1. - res);

	return 0;
}