#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <memory.h>

using namespace std;

multimap<int, int> mm;

bool visited[501] = { false, };
int n;
vector<int> v;
bool dfs(int idx, int prev) {
	v.push_back(idx);
	bool ret = false;
	visited[idx] = true;
	auto rg = mm.equal_range(idx);
	for (auto& it = rg.first; it != rg.second; it++) {
		if (it->second == prev) continue;
		if (visited[it->second]) return false;
		if (!dfs(it->second, idx)) return false;
	}
	return true;
}

int main() {
	int n, m, in1, in2, cnt;
	for (int i = 1;; i++) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		mm.clear();
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < m; j++) {
			scanf("%d%d", &in1, &in2);
			mm.insert({ in1,in2 });
			mm.insert({ in2,in1 });
		}
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				if (dfs(j, 0)) cnt++;
			}
		}
		if (cnt == 0) printf("Case %d: No trees.\n", i);
		else if (cnt == 1) printf("Case %d: There is one tree.\n", i);
		else printf("Case %d: A forest of %d trees.\n", i, cnt);
	}
	return 0;
}