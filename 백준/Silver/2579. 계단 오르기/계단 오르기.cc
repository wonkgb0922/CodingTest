#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[301] = { 0 }, n;
vector<int> v;

int solve(int i)
{
	if (dp[i] != 0) return dp[i];
	if (i >= 3) dp[i] = v[i] + max(v[i - 1] + solve(i - 3), solve(i - 2));
	else {
		if (i == 0) dp[i] = v[0];
		if (i == 1) dp[i] = v[0] + v[1];
		if (i == 2) dp[i] = max(v[0], v[1]) + v[2];
		return dp[i];
	}
	return dp[i];
}

int main(void) {
	int input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}
	cout << solve(n - 1);
}
