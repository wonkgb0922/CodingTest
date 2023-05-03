#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int ary[100000];

int main(void)
{
	int n, m, sum;
	int s = 0, e = 0, mid, cnt;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
		e += ary[i];
		if (s < ary[i]) s = ary[i];
	}
	while (s <= e)
	{
		mid = (s + e) / 2;
		sum = 0;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + ary[i] > mid)
			{
				sum = 0;
				cnt++;
			}
			sum += ary[i];
		}
		if (sum != 0) cnt++;

		if (cnt > m) s = mid + 1;
		else e = mid - 1;
	}
	cout << s;
	return 0;
}