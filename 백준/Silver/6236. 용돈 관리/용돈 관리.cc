#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int ary[100000];

int main(void)
{
	int n, m, r = 0, l = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", ary + i);
		r += ary[i];
		if (l < ary[i]) l = ary[i];
	}

	int mid, sum, cnt;
	while (l <= r)
	{
		mid = (l + r) / 2;
		sum = mid;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum - ary[i] < 0)
			{
				sum = mid - ary[i];
				cnt++;
			}
			else
			{
				sum -= ary[i];
			}
		}
		cnt++;
		if (cnt > m) l = mid + 1;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}