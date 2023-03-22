#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[500001] = { 0 };
long long S[500001] = { 0 };
int main(void) {
	int n, move = 1;
	long long sum = 0;
	cin >> n;

	scanf("%d", &ary[0]);
	S[0] = ary[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &ary[i]);
		//S[i] = ary[i] + S[i-1];
		S[i] = S[i - 1] + ary[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		sum += ary[i] * (S[n - 1] - S[i]);
		sum %= 1000000007;
	}
	cout << sum;
	return 0;
}