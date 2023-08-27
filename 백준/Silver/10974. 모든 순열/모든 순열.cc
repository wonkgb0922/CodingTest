#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int res[9], n;
bool used[9];

void dfs(int idx, int val) {
	if (used[val]) return;
	res[idx] = val;
	used[val] = true;
	if (idx + 1 == n) {
		for (int i = 0; i < n; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
		dfs(idx + 1, i);
	used[val] = false;
	
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		dfs(0, i);
	return 0;
}