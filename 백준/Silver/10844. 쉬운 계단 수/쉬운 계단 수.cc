#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define IMPOSSABLE -999999

#pragma warning (disable:4996)

using namespace std;

int n;
long long mem[101][5] = { 0, };

long long solve(int l, int digit)
{
	if (l == 1) return 1;
	if (digit < 5)
	{
		if (mem[l][digit] != 0) return mem[l][digit];
	}
	else
	{
		if (mem[l][9 - digit] != 0) return mem[l][9 - digit];
	}
	if (digit == 0)
	{
		mem[l][0] = solve(l - 1, 1);
		return mem[l][0];
	}
	if (digit == 9)
	{
		mem[l][0] = solve(l - 1, 8);
		return mem[l][0];
	}
	long long res = solve(l - 1, digit - 1) + solve(l - 1, digit + 1);
	res %= 1000000000;
	if(digit < 5) mem[l][digit] = res;
	else mem[l][9-digit] = res;
	return res;
}

int main(void) {
	scanf("%d", &n);
	int cnt = 0;
	//mem[1][0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		cnt += solve(n, i);
		cnt %= 1000000000;
	}
	cout << cnt % 1000000000;
	return 0;
}