#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int ary[10000];

int main(void)
{
	int n, c, input;
	vector<int> v;

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	int l = 1, r = v[n - 1] - v[0];

	int mid = 0, sum, cnt;
	int point;
	bool d;
	int res = -1;
	while ( l <= r )
	{
		mid = (l + r) / 2;

		sum = 0;
		cnt = 1;
		d = false;
		point = v[0];
		for (int i = 1; i < n; i++)
		{
			if (v[i] - point >= mid)
			{
				cnt++;
				point = v[i];
			}
		}
		if (cnt >= c) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	return 0;
}