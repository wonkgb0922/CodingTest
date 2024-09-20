#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n, k, ary[1000];
vector<int> v[1000];
long long dp[1000];

long long sol(int idx)
{
	long long temp = 0;
	if (v[idx].empty()) return ary[idx];
	if (dp[idx] > -1) return dp[idx];
	for (int i = 0; i < v[idx].size(); i++) {
		temp = max(temp, sol(v[idx][i]));
	}
	dp[idx] = temp + ary[idx];
	return dp[idx];
}

int main()
{
	int t, in1, in2, w;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			v[i].clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", ary + i);
		}
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &in1, &in2);
			v[in2 - 1].push_back(in1 - 1);
		}
		scanf("%d", &w);
		printf("%lld\n", sol(w - 1));
	}
	return 0;
}