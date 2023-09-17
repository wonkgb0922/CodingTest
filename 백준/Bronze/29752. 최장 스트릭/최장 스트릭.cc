#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, in, cnt = 0, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d", &in);
		if (in > 0) cnt++;
		else if (in == 0) {
			res = max(res, cnt);
			cnt = 0;
		}
	}
	res = max(res, cnt);
	cout << res;

	return 0;
}