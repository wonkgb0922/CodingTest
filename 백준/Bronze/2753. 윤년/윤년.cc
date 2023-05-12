#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	cout << ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0));
	return 0;
}