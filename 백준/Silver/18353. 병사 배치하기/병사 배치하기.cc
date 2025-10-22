#include <stdio.h>	
#include <iostream>

using namespace std;

int n;
int dp[2000], ary[2000];

int main() {
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ary[j] > ary[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}

	cout << n - res;
	return 0;
}