#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	string in;
	int b, res = 0;
	cin >> in >> b;
	reverse(in.begin(), in.end());
	for (int i = 0; i < in.length(); i++) {
		if (in[i] >= 'A' && in[i] <= 'Z') res += pow(b,i) * (in[i] - 'A' + 10);
		else res += pow(b,i) * (in[i] - '0');
	}
	cout << res;

	return 0;
}