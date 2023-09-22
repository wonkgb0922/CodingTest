#include <stdio.h>
#include <iostream>

using namespace std;
int weight[1000][3], dp[1000][3], n;

int sol(int idx, int color) {
	if (dp[idx][color] > 0) return dp[idx][color];
	if (idx == n - 1) return weight[idx][color];
	if (color == 0)
		dp[idx][color] = min(sol(idx + 1, 1), sol(idx + 1, 2));
	else if (color == 1)
		dp[idx][color] = min(sol(idx + 1, 0), sol(idx + 1, 2));
	else
		dp[idx][color] = min(sol(idx + 1, 0), sol(idx + 1, 1));
	dp[idx][color] += weight[idx][color];
	return dp[idx][color];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &weight[i][j]);
	cout << min(sol(0, 0), min(sol(0, 1), sol(0, 2)));
}