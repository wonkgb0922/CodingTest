#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
using namespace std;

bool visited[250][250] = {false };
int n,m, cnt, ary[250][250] = { 0, }, dir[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };

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
	scanf("%d%d", &n, &m);
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
	cout << cnt;

	return 0;
}