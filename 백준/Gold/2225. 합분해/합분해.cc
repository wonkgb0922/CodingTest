#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n, k;
unsigned long long dp[201][201];

unsigned long long sol(int num, int cnt) {
	if (cnt == 0) {
		if (num == 0) return 1;
		else return 0;
	}
	if (num == 0) return 1;
	if (dp[num][cnt] != -1) return dp[num][cnt];
	dp[num][cnt] = 0;
	for (int i = 0; i <= num; i++) {
		dp[num][cnt] += sol(num - i, cnt - 1);
		dp[num][cnt] %= 1000000000;
	}
	return dp[num][cnt];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	cout << sol(n, k);
}