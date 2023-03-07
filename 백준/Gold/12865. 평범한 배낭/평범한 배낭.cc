#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define IMPOSSABLE -9999999

#pragma warning (disable:4996)

using namespace std;

int n, k;
int ary[101][2] = { 0, };
long long mem[101][100001] = { 0, };

int solve(int l, int weight)
{
	if (l == n) return 0;
	if (weight == 0) return 0;
	if (mem[l][weight] != 0) return mem[l][weight];
	int res = res = solve(l + 1, weight);;
	if (weight >= ary[l][0]) res = max(res, solve(l + 1, weight - ary[l][0]) + ary[l][1]);

	mem[l][weight] = res;
	return res;
}

int main(void) {
	scanf("%d%d", &n, &k);
	int cnt = 0;
	//mem[1][0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &ary[i][0], &ary[i][1]);
	}
	cout << solve(0, k);
	return 0;
}