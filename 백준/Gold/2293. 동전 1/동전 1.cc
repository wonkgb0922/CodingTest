#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001], n;
vector<int> v;

int main(void)
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	int  input, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	//sort(v.begin(), v.end(), greater<int>());
	//sort(v.begin(), v.end());
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			dp[j] += dp[j - v[i]];
		}
	}
	cout << dp[k];
}