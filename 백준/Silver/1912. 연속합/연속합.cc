#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001];

int main(void)
{
	int n, input, res;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}

	dp[0] = v[0];
	res = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		if (dp[i] > res) res = dp[i];
	}
	cout << res;
}