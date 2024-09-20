#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, ary[100];
unsigned long long dp[100][21];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", ary + i);
	
	dp[0][ary[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + ary[i] <= 20)
					dp[i][j + ary[i]] += dp[i - 1][j];
				if (j - ary[i] >= 0)
					dp[i][j - ary[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 2][ary[n - 1]];

	return 0;
}