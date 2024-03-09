#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1500000], n;
vector<pair<int, int>> v;

int sol(int idx) {
	if (idx == n) return 0;
	if (dp[idx]) return dp[idx];
	if (idx + v[idx].first <= n)
		dp[idx] = max(sol(idx + v[idx].first) + v[idx].second, sol(idx + 1));
	else
		dp[idx] = sol(idx + 1);
	return dp[idx];
}

int main()
{
	int in1, in2;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &in1, &in2);
		v.push_back({ in1, in2 });
	}
	cout << sol(0);
}