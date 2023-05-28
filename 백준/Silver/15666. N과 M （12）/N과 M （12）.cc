#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

int n, m, ncnt = 0;
vector<int> v;
int vcnt[10001] = { 0 };
//set<int> v;
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
		if (cnt > 0)
		{
			if (res[cnt - 1] <= v[i])
			{
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
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (vcnt[input] == 0)
		{
			v.push_back(input);
			ncnt++;
			vcnt[input]++;
		}
	}
	sort(v.begin(), v.end());
	dfs(0);
}