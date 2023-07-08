#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ary[3];
	for (int i = 0; i < 3; i++)
		cin >> ary[i];

	sort(ary, ary + 3);
	cout << ary[1];
	return 0;
}