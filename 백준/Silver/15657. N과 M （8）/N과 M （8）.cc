#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
int v[8];
int res[8] = { 0 };

void dfs(int cnt)
{
	if (cnt >= m)
	{
		for (int i = 0; i < m; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (cnt > 0) {
			if (res[cnt - 1] <= v[i]) {
				res[cnt] = v[i];
				dfs(cnt + 1);
			}
		}
		else
		{
			res[cnt] = v[i];
			dfs(cnt + 1);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
	}
	sort(v, v + n);
	dfs(0);
}