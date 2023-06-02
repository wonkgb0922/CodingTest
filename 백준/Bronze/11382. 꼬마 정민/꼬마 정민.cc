#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	long long int input, sum = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		sum += input;
	}
	cout << sum;

	return 0;
}
