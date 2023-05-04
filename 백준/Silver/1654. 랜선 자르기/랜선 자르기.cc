#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int ary[10000];

int main(void)
{
	int k, n;
	long long l = 1, r = 0, mid;

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", ary + i);
		if (r < ary[i]) r = ary[i];
	}
	int cnt;
	while ( l <= r )
	{
		mid = (l + r) / 2 ;
		cnt = 0;

		for (int i = 0; i < k; i++)
			cnt += ary[i] / mid;

		if (cnt < n) r = mid - 1;
		else l = mid + 1;
	}
	cout << r;
	return 0;
}