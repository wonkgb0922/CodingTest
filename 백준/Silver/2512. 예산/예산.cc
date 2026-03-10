#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int ary[10000];

int main(void)
{
	int n, m, max = 0, Sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", ary + i);
		if (max < ary[i]) max = ary[i];
		Sum += ary[i];
	}
	cin >> m;
	if (Sum <= m)
	{
		cout << max;
		return 0;
	}
	int s = 0, e = max;
	int sum, mid;
	while (s + 1 < e)
	{
		mid = (s + e) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (ary[i] > mid) sum += mid;
			else sum += ary[i];
		}
		if (sum <= m) s = mid;
		else e = mid;
	}
	
	cout << s;

	return 0;
}