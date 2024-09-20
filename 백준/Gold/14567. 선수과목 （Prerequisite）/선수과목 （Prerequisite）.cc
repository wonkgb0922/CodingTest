#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, dp[1000];
vector<int> v[1000];

int sol(int idx)
{
	int temp = 0;
	if (v[idx].empty()) return 1;
	if (dp[idx]) return dp[idx];
	for (int i = 0; i < v[idx].size(); i++) {
		temp = max(temp, sol(v[idx][i]));
	}
	dp[idx] = temp + 1;
	return dp[idx];
}

int main()
{
	int in1, in2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in1, &in2);
		v[in2 - 1].push_back(in1 - 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", sol(i));
}