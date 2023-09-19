#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, in, res = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		res = max(res, v[i] * (i + 1));
	}
	cout << res;
	
	return 0;
}