#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[50][50] = { 0, };
int map[50][50] = { 0, };
int m, n;

void dfs(int i, int j) {
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
	int cnt, k, t, in1, in2;
	cin >> t;
	while (t--) {
		cnt = 0;
		scanf("%d%d", &m, &n);
		scanf("%d", &k);
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++)
			{
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &in1, &in2);
			map[in2][in1] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j]) {
					if (map[i][j]) {
						dfs(i, j);
						cnt++;
					}
					else visited[i][j] = true;
					
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}