#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[5001];
string s;

int sol(int idx) {
	if (idx >= s.length() - 1) {
		if (idx == s.length() - 1 && s[idx] == '0')
			return 0;
		return 1;
	}
	if (dp[idx] != -1) return dp[idx];
	
	if (s[idx] == '0') {
		dp[idx] = 0;
	}
	else if (s[idx] == '1') {
		dp[idx] = (sol(idx + 2) + sol(idx + 1)) % 1000000;
	}
	else if (s[idx] == '2') {
		if (s[idx + 1] <= '6' && s[idx + 1] >= '0') {
			dp[idx] = (sol(idx + 2) + sol(idx + 1)) % 1000000;
		}
		else dp[idx] = sol(idx + 1) % 1000000;
	}	
	else dp[idx] = sol(idx + 1) % 1000000;

	dp[idx] %= 1000000;
	return dp[idx];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> s;
	cout << sol(0);

	return 0;
}