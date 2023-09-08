#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a, b, cnt = 0;
	cin >> a;
	b = ~a;
	b++;
	for (int i = 0; i < 32; i++) {
		if (b << i ^ a << i) cnt++;
	}
	cout << cnt;
}