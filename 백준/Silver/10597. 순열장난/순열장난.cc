#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int used[51] = { 0, };
int res[50];
string s;

bool valid(int cnt) {
	for (int i = 1; i <= cnt + 1; i++)
		if (used[i] == 0) return false;
	return true;
}

bool dfs(int idx, int range, int cnt) {
	int val;
	if (range == 1) val = s[idx] - '0';
	else val = (s[idx] - '0') * 10 + s[idx + 1] - '0';
	if (val == 0 || val > 50 || used[val] > 0) return false;
	used[val]++;
	res[cnt] = val;
	if (idx + range >= s.length()) {
		if (valid(cnt)) {
			for (int i = 0; i < cnt + 1; i++)
				printf("%d ", res[i]);
			return true;
		}
		used[val]--;
		return false;
	}
	if (dfs(idx + range, 1, cnt + 1)) return true;
	else if (dfs(idx + range, 2, cnt + 1)) return true;
	used[val]--;
	return false;
}

int main()
{
	cin >> s;
	
	if (dfs(0, 1, 0)) return 0;
	else dfs(0, 2, 0);

	return 0;
}