#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
//vector<int> v;
int v[8];
int res[8] = { 0 };
bool visited[8] = { false };


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
		res[cnt] = v[i];
		dfs(cnt + 1);
	}
}

int main(void)
{
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
		//scanf("%d", &input);
		//v.push_back(input);

	}
	// sort(v.begin(), v.end());
	sort(v, v + n);
	dfs(0);
}