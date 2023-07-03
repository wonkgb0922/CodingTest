#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;
	int in1, in2;
	map<int, int> m;
	int res = 0, max, maxr = 0, maxl = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &in1, &in2);
		m.insert({ in1, in2 });
	}
	maxl = m.begin()->first;
	max = m.begin()->second;
	for (auto& x : m)
	{
		if (max < x.second)
		{
			res += (x.first - maxl) * max;
			max = x.second;
			maxl = x.first;
		}
	}
	maxr = m.rbegin()->first;
	max = m.rbegin()->second;
	for (map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
	{
		if (max < it->second)
		{
			res += (maxr - it->first) * max;
			max = it->second;
			maxr = it->first;
		}
	}
	res += (maxr - maxl + 1) * max;
	cout << res;
	return 0;
}