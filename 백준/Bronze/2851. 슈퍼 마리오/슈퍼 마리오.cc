#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;


int main(void) {
	int ary[10];
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> ary[i];
	}
	for (int i = 0; i < 10; i++)
	{
		sum += ary[i];
		if (sum == 100) break;
		if (sum > 100)
		{
			if (sum - 100 > 100 - (sum - ary[i]))
			{
				sum -= ary[i];
				break;
			}
			else break;
		}
	}
	cout << sum;
	return 0;
}