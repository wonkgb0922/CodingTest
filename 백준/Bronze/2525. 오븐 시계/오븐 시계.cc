#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int h, m, in, temp;
	cin >> h >> m;
	cin >> in;
	m += in;
	if (m >= 60) {
		temp = m / 60;
		m %= 60;
		h += temp;
		if (h >= 24) h -= 24;
	}
	printf("%d %d", h, m);
	return 0;
}