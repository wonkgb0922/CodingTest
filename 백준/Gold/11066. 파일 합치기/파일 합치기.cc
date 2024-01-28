#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int ary[501], dp[501][501], n, S[501];

int sol(int s, int e)
{
	if (dp[s][e]) return dp[s][e];
	if (s == e) return 0;
	if (s + 1 == e) return ary[s] + ary[e];
	for (int i = s; i < e; i++) {
		if (!dp[s][e])
			dp[s][e] = sol(s, i) + sol(i + 1, e);
		dp[s][e] = min(dp[s][e], sol(s, i) + sol(i + 1, e));
	}
	dp[s][e] += S[e] - S[s - 1];
	return dp[s][e];
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", ary + i);
			S[i] = S[i - 1] + ary[i];
		}
		printf("%d\n", sol(1, n));
	}

	return 0;
}