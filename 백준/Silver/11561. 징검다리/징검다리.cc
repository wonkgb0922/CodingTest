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
	int T;
	ull n;
	cin >> T;
	while (T--)
	{
		scanf("%llu", &n);
		ull s = 1, e = n, m = (e-1)/2;
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		while (1)
		{
			//printf("%llu %llu %llu\n", s, m, e);
			ull temp = m * (m + 1) / 2;
			
			if (temp < n)
			{
				s = m;
				m = (e + s) / 2;
			}
			else if (temp > n)
			{
				e = m;
				m = (e + s) / 2;
			}
			else break;
			if (e - s == 1)
			{
				m = s;
				break;
			}
		}
		printf("%llu\n", m);
	}
	return 0;
}