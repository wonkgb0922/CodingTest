#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
	int n, input;
	vector<int> a, b;
	unsigned long long res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		b.push_back(input);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < n; i++)
		res += a[i] * b[i];
	cout << res;
	return 0;
}