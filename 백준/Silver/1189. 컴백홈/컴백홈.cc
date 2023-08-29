#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

string ary[5];
bool visited[5][5] = { false, };
int dir[4][2] = { {0,1},{-1,0},{1,0},{0,-1} };
int r, c, k, cnt = 0;



void dfs(int x, int y, int fcnt) {
	visited[y][x] = true;
	if (x == c - 1 && y == 0 && fcnt == k) {
		cnt++;
		visited[y][x] = false;
		return;
	}
	if (fcnt >= k) {
		visited[y][x] = false;
		return;
	}
	
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
			if (!visited[ny][nx] && ary[ny][nx] != 'T') {
				dfs(nx, ny, fcnt + 1);
			}
		}
	}
	visited[y][x] = false;

}

int main()
{
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 0; i < r; i++)
		cin >> ary[i];
	dfs(0, r-1, 1);
	printf("%d", cnt);

	return 0;
}