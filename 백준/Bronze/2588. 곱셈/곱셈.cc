#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a * (b % 10) << endl << a * (b / 10 % 10) << endl << a * (b / 100) << endl << a * b;

	return 0;
}
