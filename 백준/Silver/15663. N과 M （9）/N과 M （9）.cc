#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ncnt = 0;
vector<int> v;
int vcnt[10001] = { 0 };
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
	for (int i = 0; i < ncnt; i++)
	{
		if (vcnt[v[i]] > 0)
		{
			res[cnt] = v[i];
			vcnt[v[i]]--;
			dfs(cnt + 1);
			vcnt[v[i]]++;
		}
	}
}

int main(void)
{
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (vcnt[input] == 0)
		{
			v.push_back(input);
			ncnt++;
		}
		vcnt[input]++;
	}
	sort(v.begin(), v.end());
	dfs(0);
}