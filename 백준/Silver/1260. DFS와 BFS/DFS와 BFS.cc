#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

multimap<int, int> g;
bool visited[1001];

void dfs(int n)
{
	vector<int> v;
	printf("%d ", n);
	auto rg = g.equal_range(n);
	for (auto& it = rg.first; it != rg.second; it++) {
		v.push_back(it->second);
	}
	sort(v.begin(), v.end());
	for (auto it : v) {
		if (!visited[it]) {
			visited[it] = true;
			dfs(it);
		}
	}
}

int main(void)
{
	int in, in2, n, m, v;
	queue<int> q;
	vector<int> vv;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &in, &in2);
		g.insert({ in,in2 });
		g.insert({ in2,in });
	}
	visited[v] = true;
	dfs(v);
	fill(visited, visited + n + 1, false);
	visited[v] = true;
	printf("\n");
	q.push(v);
	while(!q.empty()) {
		vv.clear();
		auto t = q.front();
		printf("%d ", t);
		q.pop();
		auto rg = g.equal_range(t);
		for (auto& it = rg.first; it != rg.second; it++) {
			if (!visited[it->second]) {
				visited[it->second] = true;
				vv.push_back(it->second);
			}
		}
		sort(vv.begin(), vv.end());
		for (auto it : vv)
			q.push(it);
	}
}