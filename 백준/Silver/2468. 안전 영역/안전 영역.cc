#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int ary[100][100] = { 0, }, n;
bool visited[100][100] = { false, };

void dfs(int i, int j, int k) {
	visited[i][j] = true;
	if (i < n - 1)
		if ((ary[i + 1][j] >= k) && !visited[i + 1][j]) dfs(i + 1, j, k);
	if (i > 0)
		if ((ary[i - 1][j] >= k) && !visited[i - 1][j]) dfs(i - 1, j, k);
	if (j < n - 1)
		if ((ary[i][j + 1] >= k) && !visited[i][j + 1]) dfs(i, j + 1, k);
	if (j > 0)
		if ((ary[i][j - 1] >= k) && !visited[i][j - 1]) dfs(i, j - 1, k);
}


int main()
{
	int max = 0, cnt, res = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ary[i][j]);
			if (max < ary[i][j]) max = ary[i][j];
		}
	}
		
	for (int k = 1; k <= max; k++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					if (ary[i][j] >= k) {
						dfs(i, j, k);
						cnt++;
					}
					else visited[i][j] = true;
				}
			}
		}
		if (cnt > res) res = cnt;
	}

	printf("%d", res);

	return 0;
}