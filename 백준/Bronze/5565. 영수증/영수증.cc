#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int s, in;
	cin >> s;
	for (int i = 0; i < 9; i++) {
		cin >> in;
		s -= in;
	}
	printf("%d", s);
	return 0;
}