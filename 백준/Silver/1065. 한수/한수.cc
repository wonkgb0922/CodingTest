#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
	int n, o, t, h, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		h = i / 100;
		t = (i / 10) % 10;
		o = i % 10;
		if (h != 0) {
			if (t - h == o - t) cnt++;
		}
		else cnt++;
	}
	cout << cnt;
	return 0;

}