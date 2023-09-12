#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (!(n % i)) {
			cnt++;
			if (cnt == m) {
				printf("%d", i);
				return 0;
			}
		}
		
	}
	cout << 0;
	return 0;
}