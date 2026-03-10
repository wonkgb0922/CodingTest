#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n, m = 1;

	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < min(m, 2 * n - m); j++)
			printf("*");
		printf("\n");
		m++;
	}
}