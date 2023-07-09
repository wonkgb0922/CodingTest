#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[100][100] = { 0, };
int map[100][100] = { 0, };
int cnt, m, n;

void dfs(int i, int j) {
	cnt++;
	visited[i][j] = true;
	if(i < n - 1)
		if (map[i + 1][j] && !visited[i + 1][j]) dfs(i + 1, j);
	if(i > 0)
		if (map[i - 1][j] && !visited[i - 1][j]) dfs(i - 1, j);
	if(j < m - 1)
		if (map[i][j + 1] && !visited[i][j + 1]) dfs(i, j + 1);
	if(j > 0)
		if (map[i][j - 1] && !visited[i][j - 1]) dfs(i, j - 1);
}
int main()
{
	int k, in1, in2, max = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &in1, &in2);
		map[in1 - 1][in2 - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (map[i][j]) {
					cnt = 0;
					dfs(i, j);
					if (cnt > max) max = cnt;
				}
				else visited[i][j] = true;
			}
		}
	}
	cout << max;
	return 0;
}