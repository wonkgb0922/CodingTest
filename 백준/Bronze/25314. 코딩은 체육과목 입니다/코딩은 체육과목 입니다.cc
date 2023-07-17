#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n /= 4;
	while (n--) {
		printf("long ");
	}
	printf("int");
	return 0;
}