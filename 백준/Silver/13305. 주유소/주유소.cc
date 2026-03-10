#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cost[100000];

int main(void)
{
	int n;
	unsigned long long int res = 0, cur = 0, in;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", cost + i);

	for (int i = 0; i < n; i++) {
		scanf("%ulld", &in);
		if (cur > in || !cur)
			cur = in;
		res += cur * cost[i];
	}
	cout << res;
	return 0;
}