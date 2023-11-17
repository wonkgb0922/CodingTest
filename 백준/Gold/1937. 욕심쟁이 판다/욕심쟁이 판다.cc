#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, res;
int ary[500][500], dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, dp[500][500];

int dfs(int i, int j) {
	if (dp[i][j] != 0) return dp[i][j];
	dp[i][j] = 1;
	int temp = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + dir[k][0];
		int nj = j + dir[k][1];
		if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
			if (ary[i][j] < ary[ni][nj])
				 temp = max(dfs(ni, nj), temp);
		}
	}
	dp[i][j] += temp;
	return dp[i][j];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res = max(dfs(i, j), res);
	cout << res;
}