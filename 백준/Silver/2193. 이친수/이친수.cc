#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int n;
long long ary[91] = { 0, };


int main(void){
	int cnt = 0;
	ary[1] = 1;
	ary[2] = 1;
	scanf("%d", &n);
	if (n <= 2) printf("1");
	else
	{
		for (int i = 3; i <= n; i++)
		{
			ary[i] = ary[i - 1] + ary[i - 2];
		}
		printf("%lld", ary[n]);
	}
	return 0;
}