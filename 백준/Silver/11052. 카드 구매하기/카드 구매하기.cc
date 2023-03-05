#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define IMPOSSABLE -999999

#pragma warning (disable:4996)

using namespace std;

int n;
int mem[1001][10001] = { 0, };
int ary[1001] = { 0, };

int solve(int v, int value)
{
	if (v == n + 1)
	{
		if (value > 0) return IMPOSSABLE;
		else if (value == 0) return 0;
	}
	if (mem[v][value] != 0) return mem[v][value];
	int res = solve(v + 1, value);
	if (value >= v) res = max(res, solve(v, value - v) + ary[v]);
	mem[v][value] = res;
	return res;

}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d", &ary[i]);
	}
	cout << solve(1, n);
	return 0;
}