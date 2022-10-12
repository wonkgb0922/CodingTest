/*
	1181번
	단어 정렬
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string a, const string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(void)
{
	int n;
	bool d = false;
	string s;
	vector<string> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		d = false;
		cin >> s;
		for (auto& x : v)
		{
			if (x == s)
			{
				d = true;
				break;
			}
		}
		if (d) continue;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), comp);

	for (auto& x : v)
	{
		cout << x << "\n";
	}
	return 0;

}