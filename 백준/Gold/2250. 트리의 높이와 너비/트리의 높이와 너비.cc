#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, num[10000], cnt = 1;
pair<int, int> v[10000];
int L[10001] = { 0, }, R[10001] = { 0, }, s;

void dfs(int idx, int level) {
	if (v[idx].first >= 0) dfs(v[idx].first, level + 1);
	num[idx] = cnt++;
	if (num[idx] < L[level] || !L[level]) L[level] = num[idx];
	if (num[idx] > R[level] || !R[level]) R[level] = num[idx];
	if (v[idx].second >= 0) dfs(v[idx].second, level + 1);
	if (level > s) s = level;
}

int main() {
	int in1, in2, in3, res1 = 0, res2 = 0, root = 0;
	bool go;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &in1, &in2, &in3);
		v[in1 - 1] = { in2 - 1,in3 - 1 };
	}
	while (true) {
		go = true;
		for (int i = 0; i < n; i++) {
			if (v[i].first == root || v[i].second == root) {
				root = i;
				go = false;
				break;
			}
		}
		if (go) break;
	}
	dfs(root, 1);
	for (int i = 1; i <= s; i++) {
		in1 = L[i];
		in2 = R[i];
		if (in2 - in1 + 1 > res2) {
			res2 = in2 - in1 + 1;
			res1 = i;
		}
	}
	cout << res1 << " " << res2;
	return 0;
}