#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[100][100] = { 0, };
int map[100][100] = { 0, };
int cnt, m, n;

void dfs(int i, int j) {
	cnt++;
	visited[i][j] = true;
	if (i < m - 1)
		if (!map[i + 1][j] && !visited[i + 1][j]) dfs(i + 1, j);
	if (i > 0)
		if (!map[i - 1][j] && !visited[i - 1][j]) dfs(i - 1, j);
	if (j < n - 1)
		if (!map[i][j + 1] && !visited[i][j + 1]) dfs(i, j + 1);
	if (j > 0)
		if (!map[i][j - 1] && !visited[i][j - 1]) dfs(i, j - 1);
}
int main()
{
	int k, ary[4];
	string in;
	vector<int> res;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) scanf("%d", ary + j);
		for (int j = ary[1]; j < ary[3]; j++) {
			for (int l = ary[0]; l < ary[2]; l++) {
				map[j][l] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				if (!map[i][j]) {
					cnt = 0;
					dfs(i, j);
					res.push_back(cnt);
				}
				else visited[i][j] = true;
			}
		}
	}
	printf("%d\n", res.size());
	sort(res.begin(), res.end());
	for (auto& it : res) {
		printf("%d ", it);
	}
	return 0;
}