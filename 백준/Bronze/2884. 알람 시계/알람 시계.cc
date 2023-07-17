#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	m -= 45;
	if (m < 0) {
		h--;
		m += 60;
		if (h < 0) h = 23;
	}
	printf("%d %d", h, m);
	return 0;
}