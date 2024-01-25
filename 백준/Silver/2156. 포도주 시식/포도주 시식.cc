#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];

int main(void)
{
	int n, in;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	dp[0] = v[0];
	if (n > 1)
	{
		dp[1] = v[0] + v[1];
		if (n > 2) {
			dp[2] = max(dp[1], v[1] + v[2]);
			dp[2] = max(dp[2], v[0] + v[2]);
		}
	}
	for (int i = 3; i < n; i++) {
		dp[i] = max(v[i] + dp[i - 2], v[i] + v[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n - 1];
}