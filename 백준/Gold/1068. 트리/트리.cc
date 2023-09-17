#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
multimap<int, int> mm;

int dfs(int idx, int prev) {
	if (idx == m) {
		auto rg = mm.equal_range(prev);
		auto b = rg.first;
		b++;
		if (b == rg.second) return 1;
		return 0;
	}
	int sum = 0;
	auto rg = mm.equal_range(idx);
	
	
	if (rg.first == rg.second) return 1;
	for (auto& it = rg.first; it != rg.second; it++) {
		sum += dfs(it->second, idx);
	}
	
	return sum;
}

int main() {
	int s, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		mm.insert({ in, i });
		if (in == -1) s = i;
	}
	cin >> m;
	if (s == m) cout << 0;
	else cout << dfs(s, -1);
	return 0;
}