#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

multimap<int, pair<int, int>> mm;
int n, res;

int dfs(int idx) {
	int ret = 0, sum = 0, temp;
	auto rg = mm.equal_range(idx);
	vector<int> v;
	if (rg.first == rg.second) return 0;
	for (auto& it = rg.first; it != rg.second; it++) {
		temp = dfs(it->second.first) + it->second.second;
		ret = max(ret, temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<int>());
	if (v.size() >= 2) sum = v[0] + v[1];
	else if (v.size() == 1) sum = v[0];
	res = max(res, sum);
	return ret;
}

int main(void) {
	int in1, in2, in3;
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &in1, &in2, &in3);
		mm.insert({ in1, {in2, in3} });
	}
	dfs(1);
	cout << res;
	return 0;
}