#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define IMPOSSABLE -999999

#pragma warning (disable:4996)

using namespace std;

int n;
long long mem[1001][10] = { 0, };

long long solve(int l, int digit)
{
	if (l == 1)
	{
		return 1;
		//10-digit
	}
	if (mem[l][digit] != 0)
	{
		return mem[l][digit];
	}
	long long res = 0;
	for (int i = digit; i <= 9; i++)
	{
		res += solve(l - 1, i);
		res %= 10007;
	}
	mem[l][digit] = res % 10007;
	return mem[l][digit];
}

int main(void) {
	scanf("%d", &n);
	int cnt = 0;
	//mem[1][0] = 1;
	for (int i = 0; i <= 9; i++)
	{
		cnt += solve(n, i);
		cnt %= 10007;
	}
	cout << cnt % 10007;
	return 0;
}