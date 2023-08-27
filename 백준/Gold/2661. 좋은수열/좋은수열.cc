#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool used[51] = { false, };
int res[50];
int n;

bool valid(int idx) {
	if (idx == 0) return true;
	int cnt;
	for (int i = 1; i <= (idx + 1) / 2; i++) {
		cnt = 0;
		for (int j = idx; j > idx - i; j--) {
			if (res[j] == res[j - i]) cnt++;
		}
		if (cnt == i) return false;
	}
	return true;
}

bool dfs(int idx, int val) {
	res[idx] = val;
	if (valid(idx)) {
		if (idx == n - 1) {
			for (int i = 0; i < n; i++)
				printf("%d", res[i]);
			return true;
		}
		if (dfs(idx + 1, 1)) return true;
		else if (dfs(idx + 1, 2)) return true;
		else if (dfs(idx + 1, 3)) return true;
		else return false;
	}
	else return false;
}

int main()
{
	cin >> n;
	
	if (dfs(0, 1)) return 0;
	else if (dfs(0, 2)) return 0;
	else dfs(0, 3);
	return 0;
}