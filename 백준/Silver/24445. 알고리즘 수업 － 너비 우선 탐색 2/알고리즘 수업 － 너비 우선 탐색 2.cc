#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool visited[100001];
int res[100001];

int main()
{
	int n, m, r, in, in2, temp, i = 1;
	queue<int> q;
	multimap<int, int> mm;
	priority_queue<int> qq;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in, &in2);
		mm.insert({ in,in2 });
		mm.insert({ in2,in });
	}
	q.push(r);

	visited[r] = true;
	while (!q.empty()) {
		temp = q.front();
		res[temp] = i++;
		auto rg = mm.equal_range(temp);
		for (auto& it = rg.first; it != rg.second; it++) {
			if (!visited[it->second]) {
				qq.push(it->second);
			}
		}
		while (!qq.empty()) {
			visited[qq.top()] = true;
			q.push(qq.top());
			qq.pop();
		}
		q.pop();
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", res[i]);
}