#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include <memory.h>
using namespace std;

bool visited[250][250];
int n, m, cnt, ary[250][250], dir[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };

void dfs(int y, int x) {
	int ny, nx;
	visited[y][x] = true;

	for (int i = 0; i < 8; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (ary[ny][nx] && !visited[ny][nx])
				dfs(ny, nx);
		}
	}
}

int main()
{
	while (1) {
		scanf("%d%d", &m, &n);
		if (!n && !m) break;
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &ary[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ary[i][j] && !visited[i][j]) {
					cnt++;;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}