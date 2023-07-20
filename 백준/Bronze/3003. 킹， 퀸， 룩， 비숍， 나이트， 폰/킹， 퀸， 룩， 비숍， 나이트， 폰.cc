#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ary[] = { 1,1,2,2,2,8 };
	int n;
	for (int i = 0; i < 6; i++) {
		cin >> n;
		ary[i] -= n;
		printf("%d ", ary[i]);
	}
	return 0;
}