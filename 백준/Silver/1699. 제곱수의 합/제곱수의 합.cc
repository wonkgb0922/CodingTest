#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define IMPOSSABLE 99999

#pragma warning (disable:4996)

using namespace std;

int n, CNT;
int mem[317][100001] = { 0, };
int ary[317] = { 0, };

int solve(int n, int value)
{
	if (n == CNT)
	{
		if (value > 0) return IMPOSSABLE;
		else if (value == 0) return 0;
	}
	if (mem[n][value] != 0) return mem[n][value];
	int res = solve(n + 1, value);
	if (value >= ary[n]) res = min(res, solve(n, value - ary[n]) + 1);
	mem[n][value] = res;
	return res;

}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;; i++)
	{
		if (i * i > n) break;
		ary[CNT] = i * i;
		CNT++;
	}
	if (ary[CNT -1] == n)
		cout << 1;
	else
	{
		cout << solve(0, n);
	}
	return 0;
}