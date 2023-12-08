#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool visited[100001];
int res[100001], i = 1;
multimap<int, int> mm;

void dfs(int idx) {
	priority_queue<int, vector<int>, greater<>> qq;
	visited[idx] = true;
	res[idx] = i++;
	auto rg = mm.equal_range(idx);
	for (auto& it = rg.first; it != rg.second; it++) {
		if (!visited[it->second])
			qq.push(it->second);
	}
	while (!qq.empty()) {
		if (!visited[qq.top()])
			dfs(qq.top());
		qq.pop();
	}
}

int main()
{
	int n, m, r, in, in2, temp;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in, &in2);
		mm.insert({ in,in2 });
		mm.insert({ in2,in });
	}
	dfs(r);
	for (int i = 1; i <= n; i++)
		printf("%d\n", res[i]);

	return 0;
}