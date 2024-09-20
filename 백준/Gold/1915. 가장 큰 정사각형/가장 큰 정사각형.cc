#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m, ary[1000][1000];
int dp[1000][1000];

int main() {
	string in;
	int res = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> in;
		for (int j = 0; j < m; j++)
			ary[i][j] = in[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		dp[i][0] = ary[i][0];
		res = max(res, dp[i][0]);
	}
	for(int i = 0; i < m; i++) {
		dp[0][i] = ary[0][i];
		res = max(res, dp[0][i]);
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (!ary[i][j]) dp[i][j] = 0;
			else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			res = max(res, dp[i][j]);
		}
	}
	cout << res * res;
}