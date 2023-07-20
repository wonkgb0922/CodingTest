#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> g;
bool visited[1001];

void dfs(int n)
{
	vector<int> vv;
	printf("%d ", n);
	auto d = find_if(g.begin(), g.end(), [n](const pair<int, int>& p) {return p.first == n;});
	while (d != g.end() && d->first == n)
	{
		vv.push_back(d->second);
		d++;
	}
	d = find_if(g.begin(), g.end(), [n](const pair<int, int>& p) {return p.second == n; });
	while (d != g.end())
	{
		vv.push_back(d->first);
		d++;
		d = find_if(d, g.end(), [n](const pair<int, int>& p) {return p.second == n; });
	}
	sort(vv.begin(), vv.end());
	for (auto& it : vv)
	{
		if (!visited[it])
		{
			visited[it] = true;
			dfs(it);
		}
	}
}

void bfs(int n)
{
	queue<int> q;
	vector<int> vv;
	int fir;
	q.push(n);
	while (!q.empty())
	{
		vv.clear();
		fir = q.front();
		printf("%d ", fir);
		q.pop();
		auto d = find_if(g.begin(), g.end(), [fir](const pair<int, int>& p) {return p.first == fir; });
		while (d != g.end() && d->first == fir)
		{
			if (!visited[d->second])
			{
				visited[d->second] = true;
				vv.push_back(d->second);
			}
			d++;
		}
		d = find_if(g.begin(), g.end(), [fir](const pair<int, int>& p) {return p.second == fir; });
		while (d != g.end())
		{
			if (!visited[d->first])
			{
				visited[d->first] = true;
				vv.push_back(d->first);
			}
			d++;
			d = find_if(d, g.end(), [fir](const pair<int, int>& p) {return p.second == fir; });
		}
		sort(vv.begin(), vv.end());
		for (auto it : vv) q.push(it);
	}
}

int main(void)
{
	//int cnt[1001] = { 0 };
	int fir, sec;
	int n, m, v;
	
	cin >> n >> m >> v;
	fill(visited, visited + n + 1, false);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &fir, &sec);
		g.push_back(make_pair(fir, sec));
		//cnt[fir]++;
	}
	sort(g.begin(), g.end());
	visited[v] = true;
	dfs(v);
	fill(visited, visited + n + 1, false);
	visited[v] = true;
	printf("\n");
	bfs(v);
}