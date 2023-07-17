#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--)
			printf(" ");
		for (int j = i; j > 0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}