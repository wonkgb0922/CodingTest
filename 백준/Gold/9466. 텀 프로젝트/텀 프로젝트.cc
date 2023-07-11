#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[100001] = { false, }, finished[100001] = { false, };
int map[100001] = { 0, };
int cnt, n;

void dfs(int k) {
	if (k == map[k]) {
		if (!visited[k]) {
			visited[k] = true;
			finished[k] = true;
			cnt++;
		}
		return;
	}
	visited[k] = true;
	if (!visited[map[k]]) {
		dfs(map[k]);
	}
	else {
		if (!finished[map[k]]) {
			for (int it = map[k]; it != k; it = map[it]) cnt++;
			cnt++;
		}
	}
	finished[k] = true;
}

int main()
{
	int t, n;
	cin >> t;

	while (t--) {
		scanf("%d", &n);
		cnt = 0;
		fill_n(visited, n + 1, 0);
		fill_n(finished, n + 1, 0);
		for (int i = 1; i <= n; i++) {
			scanf("%d", map + i);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		printf("%d\n", n - cnt);
	}

	return 0;
}