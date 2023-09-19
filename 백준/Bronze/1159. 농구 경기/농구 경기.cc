#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ary[27] = { 0, };
	int n, cnt = 0;
	bool sol = false;
	string in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		ary[in[0] - 'a']++;
	}
	for (int i = 0; i < 27; i++) {
		if (ary[i] >= 5) {
			printf("%c", i + 'a');
			sol = true;
		}
	}
	if (!sol) printf("PREDAJA");
	return 0;
}