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

int main(void) {
	int n;
	
	scanf("%d", &n);
	if (n == 1)
	{
		printf("5");
		return 0;
	}
	ull s = 5, e = n*5, m = (s + e) / 2;
	int res = -1;
	int cnt = 0;
	for (int i = 5; i <= e; i *= 5)
		cnt += e / i;
	if (cnt == n)
	{
		cout << e;
		return 0;
	}
	while (s <= e)
	{
		//printf("%llu %llu %llu\n", s, m, e);
		int cnt = 0;
		for (int i = 5; i <= m; i *= 5)
			cnt += m / i;
		if (cnt < n)
		{
			s = m;
			m = (s + e) / 2;
		}
		else if (cnt > n)
		{
			e = m;
			m = (s + e) / 2;
		}
		else
		{
			res = m;
			break;
		}
		if (e - s == 1) break;
	}
	if (res % 5 > 0)
		res = res - res % 5;
	printf("%d", res);
	
	return 0;
}