#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

bool visited[10] = { false, };
int weight[10][10] = { 0, };
int n, res = 10000000;

void dfs(int pos, int cnt, int sum, int st) {
	visited[pos] = true;
	if (cnt == n) {
		if(sum + weight[pos][st] < res && weight[pos][st] > 0) res = sum + weight[pos][st];
		visited[pos] = false;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i] && sum + weight[pos][i] < res && weight[pos][i] != 0) {
			dfs(i, cnt + 1, sum + weight[pos][i], st);
		}
	}
	visited[pos] = false;
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &weight[i][j]);
	}

	for (int i = 0; i < n; i++)
		dfs(i, 1, 0, i);
	cout << res;
}