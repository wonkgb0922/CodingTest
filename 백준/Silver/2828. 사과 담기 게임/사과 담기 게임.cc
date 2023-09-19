#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, k, in, L, R, res = 0;
	cin >> n >> m;
	L = 1;
	R = m;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &in);
		if (L <= in && in <= R) continue;
		if (in < L) {
			res += L - in;
			R = in + m - 1;
			L = in;
		}
		else if (R < in) {
			res += in - R;
			R = in;
			L = in - m + 1;
		}
	}
	cout << res;
	return 0;
}