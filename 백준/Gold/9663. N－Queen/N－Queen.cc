#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int ary[15] = { 0, };
int n, cnt = 0;

bool valid(int idx, int val) {
	for (int i = 0; i < n; i++) {
		if (ary[i] != 0)
			if (max(idx - i, i - idx) == max(val - ary[i], ary[i] - val))
				return false;
	}
	return true;
}

void dfs(int idx, int val) {
	ary[idx] = val;

	if (val == n) cnt++;
	for (int i = 0; i < n; i++) {
		if (ary[i] == 0 && valid(i, val + 1))
			dfs(i, val + 1);
	}
	ary[idx] = 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		dfs(i, 1);
	printf("%d", cnt);
	return 0;
}