#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string a, b;

int main()
{
	cin >> a >> b;
	if (a.length() > b.length()) swap(a, b);
	
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++)
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]));
	}
	cout << dp[a.length()][b.length()];
	return 0;
}