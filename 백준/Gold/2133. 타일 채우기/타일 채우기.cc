#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

int dp[31][1 << 4];
int n;

int sol(int idx, int state) {
	if (idx > n) return 0;
	if (idx == n) {
		if (state == 0) return 1;
		return 0;
	}
	if (dp[idx][state] != -1) return dp[idx][state];
	int& res = dp[idx][state];
	res = 0;
	if (state == 0)
		res = sol(idx + 2, 0) + sol(idx + 1, 4) + sol(idx + 1, 1);
	else if (state == 4)
		res = sol(idx + 1, 0) + sol(idx + 1, 3);
	else if (state == 3)
		res = sol(idx + 1, 4);
	else if (state == 1)
		res = sol(idx + 1, 0) + sol(idx + 1, 6);
	else if (state == 6)
		res = sol(idx + 1, 1);
	return res;
}

int main()
{
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	cout << sol(0, 0);
	return 0;
}