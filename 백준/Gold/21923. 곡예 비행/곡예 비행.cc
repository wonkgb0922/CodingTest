#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF -20000000000

using namespace std;

// 0이 상승비행, 1이 하강비행
long long dp[1000][1000][2], ary[1000][1000];
int n, m;

long long sol(int r, int c, int state)
{
	if (dp[r][c][state] != INF) return dp[r][c][state];
	if (r == n - 1 && c == 0 && !state) {
		return ary[r][c];
	}
	long long temp = INF;
	if (state) {
		// 하강비행이라면
		// 하강->하강
		if (r > 0)
			temp = max(temp, sol(r - 1, c, 1) + ary[r][c]);
		if(c > 0)
			temp = max(temp, sol(r, c - 1, 1) + ary[r][c]);

		// 상승->하강
		temp = max(temp, sol(r, c, 0) + ary[r][c]);

	}
	else {
		// 상승 비행이라면
		if (r < n - 1)
			temp = max(temp, sol(r + 1, c, 0) + ary[r][c]);
		if(c > 0)
			temp = max(temp, sol(r, c - 1, 0) + ary[r][c]);
	}
	dp[r][c][state] = temp;
	return dp[r][c][state];
}

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = INF;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%lld", &ary[i][j]);

	cout << sol(n - 1, m - 1, 1);

	return 0;
}