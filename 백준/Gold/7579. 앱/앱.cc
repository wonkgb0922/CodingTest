#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
int dp[10001][100];
vector<int> a, c;

int main()
{
	int in, s = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		a.push_back(in);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		s += in;
		c.push_back(in);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[j][i] = max(dp[j][i], dp[j][i - 1]);
			if(c[i] <= j)
				dp[j][i] = max(dp[j][i], dp[j - c[i]][i - 1] + a[i]);
		}
	}
	for (int i = 0; i <= s; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] >= m) {
				printf("%d", i);
				return 0;
			}
		}
	}

}