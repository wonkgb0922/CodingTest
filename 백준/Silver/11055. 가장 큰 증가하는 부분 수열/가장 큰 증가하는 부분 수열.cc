#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;
typedef unsigned long long ull;

int ary[1000] = { 0 };
int dp[1000] = { 0 };
int n;

int list(int pos)
{
	int cnt = ary[pos];
	if (dp[pos] != 0) return dp[pos];

	if (pos + 1 == n)
	{
		return ary[pos];
	}
	for (int i = pos + 1; i < n; i++)
	{
		if (ary[pos] < ary[i])
		{
			cnt += list(i);
			if (dp[pos] < cnt) dp[pos] = cnt;
			cnt = ary[pos];
		}
	}
	if (dp[pos] < cnt) dp[pos] = cnt;
	return dp[pos];
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int max = 0, cnt;
	for (int i = 0; i < n; i++)
	{
		cnt = list(i);
		if (max < cnt) max = cnt;
	}
	cout << max;

	return 0;
}