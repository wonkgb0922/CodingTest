#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	cout << max(a - b, b - a);
	return 0;
}