#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 2000000000

using namespace std;

int dp[1000][3][3], cost[1000][1000], n;

int dfs(int idx, int color, int start) {
	if (dp[idx][color][start] != 0) return dp[idx][color][start];
	if (idx == n - 1) {
		if(color == start)
			return INF;
		return cost[idx][color];
	}
	if (color == 0) {
		dp[idx][color][start] = min(dfs(idx + 1, 1, start), dfs(idx + 1, 2, start));
	}
	else if (color == 1) {
		dp[idx][color][start] = min(dfs(idx + 1, 0, start), dfs(idx + 1, 2, start));
	}
	else if (color == 2) {
		dp[idx][color][start] = min(dfs(idx + 1, 0, start), dfs(idx + 1, 1, start));
	}
	dp[idx][color][start] += cost[idx][color];
	return dp[idx][color][start];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	printf("%d", min(min(dfs(0, 0, 0), dfs(0, 1, 1)), dfs(0, 2, 2)));
	return 0;
}