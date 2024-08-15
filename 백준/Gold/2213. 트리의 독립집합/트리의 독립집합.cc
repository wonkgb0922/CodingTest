#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int dp[10000][2], w[10000], n;
bool visited[10000];

vector<int> v[10000], ary;

int sol(int idx, int p)
{
	if (dp[idx][p] > -1) return dp[idx][p];
	int flag = 1;
	visited[idx] = true;
	dp[idx][p] = 0;
	for (auto& it : v[idx]) {
		if (!visited[it]) {
			flag = 0;
			if (p)
				dp[idx][p] += sol(it, 0);
			else
				dp[idx][p] += max(sol(it, 0), sol(it, 1));
		}		
	}
	if (p) dp[idx][p] += w[idx];
	visited[idx] = false;
	if (flag && p) return w[idx];

	return dp[idx][p];
}

void sol2(int idx, int p)
{
	visited[idx] = true;
	if (p) {
		ary.push_back(idx + 1);
		for (auto& it : v[idx]) {
			if (!visited[it])
				sol2(it, 0);
		}
	}
	else {
		for (auto& it : v[idx]) {
			if (!visited[it]) {
				if (dp[it][0] >= dp[it][1])
					sol2(it, 0);
				else sol2(it, 1);
			}
		}
	}
	visited[idx] = false;
}

int main()
{
	int in, in2, res;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", w + i);
	while (scanf("%d%d", &in, &in2) != EOF) {
		v[in2 - 1].push_back(in - 1);
		v[in - 1].push_back(in2 - 1);
	}
	res = max(sol(0, 0), sol(0, 1));
	cout << res << '\n';
	if (dp[0][1] == res)
		sol2(0, 1);
	else
		sol2(0, 0);

	sort(ary.begin(), ary.end());
	for (auto& it : ary)
		printf("%d ", it);
	return 0;
}