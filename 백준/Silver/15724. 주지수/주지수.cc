#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, dp[1025][1025];

int main()
{
	int in, in2, in3, in4;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &in);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + in - dp[i - 1][j - 1];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d%d", &in, &in2, &in3, &in4);
		printf("%d\n", dp[in3][in4] - (dp[in - 1][in4] + dp[in3][in2 - 1]) + dp[in - 1][in2 - 1]);
	}
	return 0;
}