#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, in1, in2;
	vector<int> v;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		reverse(v.begin() + in1 - 1, v.begin() + in2);
	}
	for (auto& x : v) {
		printf("%d ", x);
	}
}