#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	int cnt;
	cin >> n >> k;
	int l = 1, r = k, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);
		if (cnt >= k) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}
