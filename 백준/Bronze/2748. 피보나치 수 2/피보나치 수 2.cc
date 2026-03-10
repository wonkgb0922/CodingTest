#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long dp[100];

long long fibo(int n)
{
	if(dp[n]) return dp[n];
	if (n <= 2)
	{
		if (n <= 0) return 0;
		return 1;
	}
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	cin >> n;
	printf("%lld", fibo(n));
	return 0;

}