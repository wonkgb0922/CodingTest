#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[32][32], N, L;
long long int I;
char res[32];

int sol(int n, int m) {
	if (dp[n][m] != -1) return dp[n][m];
	if (n == 0 || m == 0) return dp[n][m] = 1;

	dp[n][m] = sol(n - 1, m) + sol(n - 1, m - 1);

	return dp[n][m];
}

void build(int n, int m, long long int k, int idx)
{
	if (n == 0) {
		res[idx] = '\0';
		return;
	}
	if (m == 0) {
		int i;
		for (i = 0; i < n; i++)
			res[idx + i] = '0';
		res[idx + i] = '\0';
		return;
	}
	int pivot = sol(n - 1, m);
	if (k < pivot) {
		res[idx] = '0';
		build(n - 1, m, k, idx + 1);
	}
	else {
		res[idx] = '1';
		build(n - 1, m - 1, k - pivot, idx + 1);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> L >> I;
    
	build(N, L, I - 1, 0);

	cout << res;
	return 0;
}