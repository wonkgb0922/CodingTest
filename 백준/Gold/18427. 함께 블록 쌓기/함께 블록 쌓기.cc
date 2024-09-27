#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> v[50];
int dp[50][1001];

int main()
{
	int n, m, h, t;
	string in;
	scanf("%d%d%d", &n, &m, &h);

	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, in, '\n');
		t = 0;
		for (int j = 0; j < in.length(); j++) {
			if (in[j] == ' ') {
				v[i].push_back(t);
				t = 0;
				continue;
			}
			t *= 10;
			t += in[j] - '0';
		}
		v[i].push_back(t);
	}
	dp[0][0] = 1;
	for (auto& it : v[0])
		dp[0][it]++;
	for (int i = 1; i < n; i++) {
		dp[i][0] = 1;
		for (auto& it : v[i])
			dp[i][it]++;

		for (int j = 1; j <= h; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 10007;
			if (dp[i - 1][j]) {
				for (auto& it : v[i]) {
					if (j + it <= h) {
						dp[i][j + it] += dp[i - 1][j];
						dp[i][j + it] %= 10007;
					}
				}
			}
		}
			
	}

	cout << dp[n-1][h];
	return 0;
}