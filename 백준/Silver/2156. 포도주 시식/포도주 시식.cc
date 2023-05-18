#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int dp[10001];
int n;
vector<int> v;

int solve(int i)
{
	if (dp[i] != -1) return dp[i];
	if (i <= 2)
	{
		if (i == 0) dp[i] = v[0];
		if (i == 1) dp[i] = v[0] + v[1];
		if (i == 2)
		{
			dp[i] = max(dp[1], v[1] + v[2]);
			dp[i] = max(dp[i], v[0] + v[2]);
		}
		return dp[i];
	}
	dp[i] = max(v[i] + solve(i - 2), v[i] + v[i - 1] + solve(i - 3));
	dp[i] = max(dp[i], solve(i - 1));
	return dp[i];
}

int main(void)
{

	int input;
	scanf("%d", &n);
	memset(dp, -1, sizeof(int) * 10001);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	//printf("%d", solve(n - 1));
	dp[0] = v[0];
	if (n > 1)
	{
		dp[1] = v[0] + v[1];
		if (n > 2)
		{
			dp[2] = max(dp[1], v[1] + v[2]);
			dp[2] = max(dp[2], v[0] + v[2]);
		}
	}
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(v[i] + dp[i-2], v[i] + v[i - 1] + dp[i-3]);
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n - 1];
}