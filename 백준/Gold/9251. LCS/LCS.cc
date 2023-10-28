#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000][1000];
string a, b;

int main()
{
	cin >> a >> b;
	dp[0][0] = a[0] == b[0];

	for (int i = 1; i < b.length(); i++)
		dp[0][i] = max(dp[0][i - 1], (a[0] == b[i]) ? 1 : 0);
	for (int i = 1; i < a.length(); i++)
		dp[i][0] = max(dp[i - 1][0], (a[i] == b[0]) ? 1 : 0);
	for (int i = 1; i < a.length(); i++)
		for (int j = 1; j < b.length(); j++)
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (a[i] == b[j]));
	cout << dp[a.length() - 1][b.length() - 1];

	return 0;
}