#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
int ary[500][500], dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, dp[500][500];

int dfs(int i, int j) {
	if (i == n - 1 && j == m - 1) return 1;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + dir[k][0];
		int nj = j + dir[k][1];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if (ary[i][j] > ary[ni][nj])
				dp[i][j] += dfs(ni, nj);
		}
	}
	return dp[i][j];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &ary[i][j]);

	cout << dfs(0, 0);
}