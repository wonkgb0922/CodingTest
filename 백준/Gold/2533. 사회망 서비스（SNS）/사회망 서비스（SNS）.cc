#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, dp[1000000][2];
multimap<int, int> mm;
bool visited[1000000];

int dfs(int idx, int d) {
	if (dp[idx][d] > 0) return dp[idx][d];
	visited[idx] = true;
	auto rg = mm.equal_range(idx);
	if (d) {
		for (auto& it = rg.first; it != rg.second; it++) {
			if (!visited[it->second])
				dp[idx][d] += min(dfs(it->second, 0), dfs(it->second, 1));
		}
		dp[idx][d]++;
	}
	else {
		for (auto& it = rg.first; it != rg.second; it++) {
			if (!visited[it->second])
				dp[idx][d] += dfs(it->second, 1);
		}
	}
	visited[idx] = false;
	return dp[idx][d];
}

int main() {
	int u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		mm.insert({ u - 1,v - 1 });
		mm.insert({ v - 1,u - 1 });
	}
	cout << min(dfs(0, 0), dfs(0, 1));
	return 0;
}