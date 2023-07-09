#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[25][25] = { 0, };
int map[25][25] = { 0, };
int cnt, n;

void dfs(int i, int j) {
	cnt++;
	visited[i][j] = true;
	if(i < n - 1)
		if (map[i + 1][j] && !visited[i + 1][j]) dfs(i + 1, j);
	if(i > 0)
		if (map[i - 1][j] && !visited[i - 1][j]) dfs(i - 1, j);
	if(j < n - 1)
		if (map[i][j + 1] && !visited[i][j + 1]) dfs(i, j + 1);
	if(j > 0)
		if (map[i][j - 1] && !visited[i][j - 1]) dfs(i, j - 1);
}
int main()
{
	int max = 0;
	string in;
	vector<int> res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		for (int j = 0; j < n; j++) {
			map[i][j] = in[j] - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				if (map[i][j]) {
					cnt = 0;
					dfs(i, j);
					res.push_back(cnt);
					max++;
				}
				else visited[i][j] = true;
			}
		}
	}
	printf("%d\n", max);
	sort(res.begin(), res.end());
	for (auto& it : res) {
		printf("%d\n", it);
	}
	return 0;
}