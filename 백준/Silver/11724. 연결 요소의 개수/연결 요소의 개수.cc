#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool visited[1001] = { false, };
multimap<int, int> mp;
int cnt = 0;

void dfs(int v) {
	visited[v] = true;
	auto p = mp.equal_range(v);
	for (auto& it = p.first; it != p.second; it++) {
		if (!visited[it->second]) {
			dfs(it->second);
		}
	}
}

int main()
{
	int n, m, in1, in2;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		mp.insert({ in1, in2 });
		mp.insert({ in2, in1 });
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}