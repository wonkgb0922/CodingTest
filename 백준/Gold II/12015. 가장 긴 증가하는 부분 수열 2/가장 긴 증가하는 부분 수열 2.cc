#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int n, in;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		auto t = lower_bound(v.begin(), v.end(), in);
		if (t != v.end()) *t = in;
		else v.push_back(in);
	}
	cout << v.size();

	return 0;
}