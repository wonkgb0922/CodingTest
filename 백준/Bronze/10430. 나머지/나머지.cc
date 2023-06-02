#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) % c << endl << ((a % c) + (b % c)) % c << endl << (a*b) % c << endl << ((a % c) * (b % c)) % c;

	return 0;
}
