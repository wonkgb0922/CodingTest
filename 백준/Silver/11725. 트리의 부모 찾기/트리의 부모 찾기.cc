#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<pair<int, int>> v;
multimap<int, int> m1, m2;
bool visited[100001] = { false };
int res[100001] = { 0 };
void bfs(int num)
{
	queue<pair<int,int>> q;
	int temp = 0;

	q.push(make_pair(num, 0));
	while (!q.empty())
	{
		res[q.front().first] = q.front().second;
		temp = q.front().first; // 1
		q.pop();
		
		auto range = m1.equal_range(temp);
		for (auto& it = range.first; it != range.second; it++)
		{
			if (!visited[it->second])
			{
				visited[it->second] = true;
				q.push(make_pair(it->second, temp));
			}
		}
		range = m2.equal_range(temp);
		for (auto& it = range.first; it != range.second; it++)
		{
			if (!visited[it->second])
			{
				visited[it->second] = true;
				q.push(make_pair(it->second, temp));
			}
		}
		
	}	
}

int main(void)
{
	int n;
	int fir, sec;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &fir, &sec);
		m1.insert({ fir, sec });
		m2.insert({ sec, fir });
	}
	//sort(v.begin(), v.end());
	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", res[i]);
	}
	return 0;
}