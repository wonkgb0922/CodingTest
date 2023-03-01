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
	long long cnt = 0;
	ary[1] = 1;
	ary[2] = 1;
	scanf("%d", &n);
	if (n <= 2) printf("1");
	else
	{
		for (int i = 1; i <= n-2; i++)
		{
			ary[i+2] = ary[i + 1] + ary[i];
		}
		printf("%lld", ary[n]);
	}
	return 0;
}