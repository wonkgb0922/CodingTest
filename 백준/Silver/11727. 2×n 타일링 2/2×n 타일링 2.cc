#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int n;
unsigned long long ary[1001] = { 0, };


int main(void) {
	ary[1] = 1;
	ary[2] = 3;
	scanf("%d", &n);
	if (n <= 2) cout << ary[n];
	else
	{
		for (int i = 3; i <= n; i++)
		{
			ary[i] = ary[i-1] + (ary[i-2] * 2);
			ary[i] %= 10007;
		}
		cout << ary[n];
	}
	return 0;
}