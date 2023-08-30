#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int ary[16][16], dp[16][1<<16], n;
const int IMPOSSABLE = 1000000000;

int tsp(int idx, int route) {
	int& ret = dp[idx][route];
	if (ret != -1) return ret;
	if (route == (1 << n) - 1) {
		if (ary[idx][0] != 0) return ary[idx][0];
		return IMPOSSABLE;
	}
	ret = IMPOSSABLE;
	for (int i = 0; i < n; i++) {
		if (ary[idx][i] == 0 || route & (1 << i)) continue;
		ret = min(ret, tsp(i, route | 1 << i) + ary[idx][i]);
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", tsp(0, 1));
	return 0;
}