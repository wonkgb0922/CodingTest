#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, two = 0, five = 0, temp;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		temp = i;
		while (!(temp % 2))
		{
			two++;
			temp /= 2;
		}
		while (!(temp % 5))
		{
			five++;
			temp /= 5;
		}
	}
	cout << min(two, five);
	return 0;
}
