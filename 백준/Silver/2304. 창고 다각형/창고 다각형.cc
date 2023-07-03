#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int main()
{
	int n;
	int in1, in2;
	map<int, int> m;
	stack<pair<int, int>> st;
	int res = 0, maxi, maxr = 0, maxl = 0, il;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &in1, &in2);
		m.insert({ in1, in2 });
	}
	//st.push(*m.begin());
	maxl = m.begin()->second;
	maxi = m.begin()->first;
	for (auto& x : m)
	{
		if (maxl < x.second)
		{
			res += (x.first - maxi) * maxl;
			maxl = x.second;
			maxi = x.first;
		}
	}
	il = maxi;

	maxi = m.rbegin()->first;
	maxr = m.rbegin()->second;
	for (map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
	{
		if (maxr < it->second)
		{
			res += (maxi - it->first) * maxr;
			maxr = it->second;
			maxi = it->first;
		}
	}
	res += (maxi - il + 1) * maxl;
	cout << res;
	return 0;
}