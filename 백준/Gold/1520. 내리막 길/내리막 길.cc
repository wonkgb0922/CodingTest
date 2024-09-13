#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[500][500], ary[500][500], dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int n, m;

int sol(int i, int j)
{
	if (!i && !j) return 1;
	if (dp[i][j] > -1) return dp[i][j];
	dp[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int ti = i + dir[k][0];
		int tj = j + dir[k][1];
		if (ti >= 0 && ti < n && tj >= 0 && tj < m) {
			if (ary[ti][tj] > ary[i][j])
				dp[i][j] += sol(ti, tj);
		}
	}
	return dp[i][j];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &ary[i][j]);
	memset(dp, -1, sizeof(dp));
	cout << sol(n - 1, m - 1);
	return 0;
}