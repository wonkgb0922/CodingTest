#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int zero[41] = { 0, };
int one[41] = { 0, };

int fiboOne(int n) {
	if (one[n] != -1) return one[n];
	one[n] = fiboOne(n - 1) + fiboOne(n - 2);
	return one[n];	
}
int fiboZero(int n) {
	if (zero[n] != -1) return zero[n];
	zero[n] = fiboZero(n - 1) + fiboZero(n - 2);
	return zero[n];
}

int main()
{
	int t, n;

	fill_n(zero, 41, -1);
	fill_n(one, 41, -1);
	zero[0] = 1;
	zero[1] = 0;
	one[1] = 1;
	one[0] = 0;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		printf("%d %d\n", fiboZero(n), fiboOne(n));
	}
	return 0;
}