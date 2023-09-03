#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
const int INF = 2000000000;
using namespace std;

int dp[1 << 16], ary[16][16] = { 0 };
int n, des = 0;

int sol(int state, int cnt) {
	if (cnt >= des) return 0;
	if (dp[state] != -1) return dp[state];
	int& res = dp[state], stemp;

	res = INF;
	for (int i = 0; i < n; i++) {
		if (!(state & (1 << i))) {
			stemp = INF;
			for (int j = 0; j < n; j++)
				if (state & (1 << j)) stemp = min(stemp, ary[n - j - 1][n - i - 1]);
			if (stemp == INF) return -1;
			res = min(res, sol(state | (1 << i), cnt + 1) + stemp);
		}
	}

	return res;

}

int main()
{
	int state = 0, oncnt = 0;
	char in = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
	}
	getchar();
	for (int i = n - 1; i >= 0; i--) {
		scanf("%c", &in);
		if (in == 'Y') {
			state |= 1 << i;
			oncnt++;
		}
	}
	getchar();
	scanf("%d", &des);
	memset(dp, -1, sizeof(dp));
	cout << sol(state, oncnt);
	return 0;
}