#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int height[1000000];

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &height[i]);

	int s = 0, e = 1000000000, mid;
	long long sum;
	while (s + 1 < e)
	{
		mid = (s + e) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (height[i] > mid) sum += height[i] - mid;
		}
		if (sum < m) e = mid;
		else s = mid;
	}

	cout << s;

}