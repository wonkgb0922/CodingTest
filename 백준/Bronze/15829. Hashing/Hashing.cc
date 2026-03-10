#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	long long res = 0, temp;
	char in;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &in);
		temp = 1;
		for (int j = 0; j < i; j++) {
			temp *= 31;
			temp %= 1234567891;
		}
		res += ((in - 'a' + 1) * temp) % 1234567891;
		res %= 1234567891;
	}
	cout << res;
	return 0;
}