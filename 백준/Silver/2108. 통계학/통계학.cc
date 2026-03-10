#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}

int main(void)
{
	int n, avg, input;
	int sum = 0;
	int j;
	vector<int> v;
	vector<pair<int, int>> v2;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (j = 0; j < v2.size(); j++)
		{
			if (v2[j].first == input) {
				v2[j].second++;
				break;
			}
		}
		if (j == v2.size())
		{
			v2.push_back(pair<int, int>(input, 1));
		}
		sum += input;
		v.push_back(input);
	}
	avg = round((double)sum / n);
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end(), comp);

	printf("%d\n%d\n", avg, v[n/2]);
	if (v2.size() >= 2)
	{
		if (v2[0].second == v2[1].second) printf("%d\n", v2[1].first);
		else printf("%d\n", v2[0].first);
	}
	else printf("%d\n", v2[0].first);
	printf("%d", v.back() - v.front());

	return 0;

}