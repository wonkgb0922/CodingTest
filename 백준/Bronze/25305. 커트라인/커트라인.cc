#include <stdio.h>
#include <iostream>

using namespace std;


int main(void)
{
	int n, k;
	int ary[1000] = { 0 };

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (ary[j] < ary[j + 1])
			{
				int temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	cout << ary[k - 1];
	return 0;

}