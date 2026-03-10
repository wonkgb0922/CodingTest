#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int a, b;
	int sum = 0;
	int min = 10000;
	bool res = true;

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (i == 1) continue;
		if (i % 2 == 0 && i != 2) continue;
		for (int j = 3; j < i / 2; j++)
		{
			if (i % j == 0)
			{
				res = false;
				break;
			}
		}
		if (res)
		{
			if (min > i) min = i;
			sum += i;
		}
		res = true;
	}
	if (sum == 0) sum = -1;
	cout << sum;
	if(sum != -1) cout << "\n" << min;
	return 0;
	
}