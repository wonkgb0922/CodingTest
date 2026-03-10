/*
	11651번 : 정렬
	좌표 정렬하기 2
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	int n;
	int a, b;
	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end(), comp);

	for (auto& x : v)
	{
		printf("%d %d\n", x.first, x.second);
	}
	return 0;

}