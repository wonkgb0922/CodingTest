#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	printf("%d\n%d\n%d\n%d\n%d", a + b, a - b, a * b, a / b, a % b);

	return 0;
}
