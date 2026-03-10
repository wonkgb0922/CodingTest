#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	int n, in, m, sum = 0;
	vector<int> v;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> in;
		v.push_back(in);
	}
	m = round(n * 15 / 100.);
	sort(v.begin(), v.end());
	v.erase(v.end() - m, v.end());
	v.erase(v.begin(), v.begin() + m);
	for (auto it : v)
		sum += it;
	cout << round(sum / (float)v.size());

	return 0;
}