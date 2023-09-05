#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

long long int dp[101][1 << 10][10], n;

long long int sol(int state, int pos, int last) {
	if (pos == n) {
		if (state == 1023) return 1;
		return 0;
	}
	if (dp[pos][state][last] != -1) return dp[pos][state][last];
	long long int& res = dp[pos][state][last];
	res = 0;
	if(last + 1 <= 9)
		res += sol(state | (1 << last + 1), pos + 1, last + 1);
	if (last - 1 >= 0)
		res += sol(state | (1 << last - 1), pos + 1, last - 1);
	return res % 1000000000;
}

int main()
{
	long long int cnt = 0;
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++)
		cnt += sol(1 << i, 1, i);
	cout << cnt % 1000000000;
	return 0;
}