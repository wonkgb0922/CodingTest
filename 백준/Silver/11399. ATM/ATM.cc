#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, in, sum = 0, res = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		sum += v[i];
		res += sum;
	}
	cout << res;
	return 0;
}