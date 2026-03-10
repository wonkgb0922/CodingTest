#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, input;
	int cnt = 0;
	bool res = true;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 1) continue;
		if (input % 2 == 0 && input != 2) continue;
		for (int j = 3; j < input / 2; j++)
		{
			if (input % j == 0)
			{
				res = false;
				break;
			}
		}
		if(res) cnt++;
		res = true;
	}

	cout << cnt;
	return 0;
	
}