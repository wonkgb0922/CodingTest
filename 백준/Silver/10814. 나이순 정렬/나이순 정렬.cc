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

bool comp(const pair<pair<int, string>, int> a, const pair<pair<int, string>, int> b)
{
	if (a.first.first == b.first.first) return a.second < b.second;
	return a.first.first < b.first.first;
}

int main(void)
{
	int n;
	int age;
	string s;
	vector<pair<pair<int, string>, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> age >> s;
		v.push_back(pair<pair<int, string>, int>(pair<int, string>(age, s), i));
	}
	sort(v.begin(), v.end(), comp);

	for (auto& x : v)
	{
		cout << x.first.first << " " << x.first.second << "\n";
	}
	return 0;

}