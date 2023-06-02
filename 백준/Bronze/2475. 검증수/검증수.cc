#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int input, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> input;
		sum += input * input;
	}
	cout << sum % 10;

	return 0;
}
