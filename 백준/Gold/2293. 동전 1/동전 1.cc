#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];

int main(void)
{
	int  input, n, k;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = v[i]; j <= k; j++)
			dp[j] += dp[j - v[i]];
	cout << dp[k];
}