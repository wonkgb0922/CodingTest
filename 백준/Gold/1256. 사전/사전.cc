#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
unsigned long long dp[101][101];

unsigned long long sol(int n, int m)
{
	if (dp[n][m]) return dp[n][m];
	if (!n || !m) dp[n][m] = 1;
	else dp[n][m] = sol(n - 1, m) + sol(n, m - 1);
	
	return dp[n][m];
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	sol(n, m);
	
	if (k > sol(n, m)) cout << -1;
	else {
		string res;
		while (m > 0 && n > 0) {
			if (dp[n - 1][m] >= k) {
				res += 'a';
				n--;
			}
			else {
				res += 'z';
				k -= dp[n - 1][m];
				m--;
			}
		}
		while (n > 0) {
			res += 'a';
			n--;
		}
		while (m > 0) {
			res += 'z';
			m--;
		}
		cout << res;
	}
}