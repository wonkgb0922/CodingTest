#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < max(n - 1 - i, i - n + 1); j++)
			printf(" "); 
		for (int j = 0; j < 2*n - 1 - max(n - 1 - i, i - n + 1) * 2 ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}