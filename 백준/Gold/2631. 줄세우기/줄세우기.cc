#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ary[200];
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", ary + i);
	v.push_back(ary[0]);
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(v.begin(), v.end(), ary[i]);
		if (it != v.end()) *it = ary[i];
		else v.push_back(ary[i]);
	}
	cout << n - v.size();
	return 0;
}