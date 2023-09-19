#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b, c, res = 0;
	cin >> n;
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == b && b == c) res = max(res, 10000 + 1000 * a);
		else if (a == b || a == c) res = max(res, 1000 + 100 * a);
		else if (b == c) res = max(res, 1000 + 100 * b);
		else res = max(res, 100 * max(max(a, b), c));
	}
	cout << res;
	return 0;
}