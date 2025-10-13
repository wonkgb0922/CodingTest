#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#define inf 1000000000

using namespace std;

int n;
string stt, des;
int dp[10001][10];

int main()
{
	int resi, cur, to, res = inf, temp;
	stack<pair<int, int>> s;
	cin >> n >> stt >> des;

	fill(dp[0], dp[10001], inf);

	cur = stt[0] - '0';
	to = des[0] - '0';
	dp[0][0] = cur - to;
	if (dp[0][0] < 0) dp[0][0] += 10;
	temp = to - cur;
	if (temp < 0) temp += 10;
	dp[0][temp] = temp;

	for (int i = 0; i < n - 1; i++) {
		to = des[i + 1] - '0';
		for (int j = 0; j < 10; j++) {
			if (dp[i][j] == inf)
				continue;
			cur = (stt[i + 1] - '0' + j) % 10;

			temp = cur - to;
			if (temp < 0) temp += 10;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + temp);

			temp = to - cur;
			if (temp < 0) temp += 10;
			dp[i + 1][(j + temp) % 10] = min(dp[i + 1][(j + temp) % 10], dp[i][j] + temp);
		}
	}
	for (int j = 0; j < 10; j++) {
		if (res > dp[n - 1][j]) {
			res = dp[n - 1][j];
			resi = j;
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		to = des[i + 1] - '0';
		for (int j = 0; j < 10; j++) {
			if (dp[i][j] == inf) continue;
			cur = (stt[i + 1] - '0' + j) % 10;
			

			temp = cur - to;
			if (temp < 0) temp += 10;
			if (j == resi && dp[i][j] + temp == dp[i + 1][resi]) {
				if(temp != 0) s.push({i + 2, -temp});
				resi = j;
				break;
			}
			temp = to - cur;
			if (temp < 0) temp += 10;
			if ((j + temp) % 10 == resi && dp[i][j] + temp == dp[i + 1][resi]) {
				if(temp != 0) s.push({ i + 2, temp });
				resi = j;
				break;
			}
		}
	}
	if (resi != 0)		
		s.push({ 1, resi });
	else if(dp[0][resi] != 0)
		s.push({ 1, -dp[0][resi] });
	printf("%d\n", res);
	while (!s.empty()) {
		auto t = s.top();
		printf("%d %d\n", t.first, t.second);
		s.pop();
	}
	return 0;
}