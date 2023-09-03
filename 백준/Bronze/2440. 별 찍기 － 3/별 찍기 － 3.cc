#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int j = i; j > 0; j--)
            printf("*");
		printf("\n");
	}
	return 0;
}