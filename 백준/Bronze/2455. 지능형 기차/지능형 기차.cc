#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int in1, in2, res = 0, cur = 0;
	for (int i = 0; i < 4; i++) {
		cin >> in1 >> in2;
		cur -= in1;
		cur += in2;
		res = max(res, cur);
	}
	cout << res;
	return 0;
}