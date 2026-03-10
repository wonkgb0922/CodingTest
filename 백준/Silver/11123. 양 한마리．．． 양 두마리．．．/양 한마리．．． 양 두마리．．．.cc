#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include <memory.h>
using namespace std;

bool visited[100][100];
int n, m, cnt, dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
char ary[100][100];

void dfs(int y, int x) {
	int ny, nx;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (ary[ny][nx]=='#' && !visited[ny][nx])
				dfs(ny, nx);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				scanf(" %c", &ary[i][j]);
			getchar();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ary[i][j] == '#' && !visited[i][j]) {
					cnt++;;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}