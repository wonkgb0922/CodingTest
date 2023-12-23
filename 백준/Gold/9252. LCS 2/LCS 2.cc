#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string a, b, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++)
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]));
	}

	int i = a.length(), j = b.length();
	while (i > 0 && j > 0) {
		if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
			res += b[j - 1];
			i--, j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j])
			i--;
		else if (dp[i - 1][j] < dp[i][j - 1] && dp[i][j - 1] == dp[i][j])
			j--;
		else j--;
	}
	reverse(res.begin(), res.end());
	
	cout << dp[a.length()][b.length()] << '\n' << res;
	return 0;
}