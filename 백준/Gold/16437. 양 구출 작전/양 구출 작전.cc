#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n;
multimap<int, int> mm;
bool isSheep[123456] = { false, };
int cnt[123456];


long long int dfs(int idx) {
	long long int sum = 0;
	auto rg = mm.equal_range(idx);
	
	if (rg.first == rg.second) {
		if (isSheep[idx]) return cnt[idx];
		return 0;
	}
	for (auto& it = rg.first; it != rg.second; it++) {
		sum += dfs(it->second);
	}
	sum += cnt[idx];
	if (sum < 0) sum = 0;
	return sum;
}

int main() {
	int s, in2, in3;
	char in1;
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf(" %c %d%d", &in1, &in2, &in3);
		if (in1 == 'S') {
			isSheep[i] = true;
			cnt[i] = in2;
		}
		else cnt[i] = -in2;
		
		mm.insert({ in3 - 1, i});
	}
	cout << dfs(0);
	return 0;
}