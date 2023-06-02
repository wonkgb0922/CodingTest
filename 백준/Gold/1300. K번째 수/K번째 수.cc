#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	int cnt;
	cin >> n >> k;
	int l = 1, r = k, mid, res = 0, i;
	while (l <= r)
	{
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);

		//printf("%lld %lld %lld, %d\n", l, mid, r, cnt);
		if (cnt >= k)
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
	return 0;
}
