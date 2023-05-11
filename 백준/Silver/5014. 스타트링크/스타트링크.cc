#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int f, s, g, u, d;
bool visited[1000001] = { false };

int bfs(int num)
{
	queue<pair<int,int>> q;
	int level = 1;
	q.push(make_pair(num, 0));
	int temp;
	while (!q.empty())
	{
		temp = q.front().first;
		level = q.front().second + 1;

		q.pop();

		if (temp + u == g || temp - d == g) return level;
		
		if (temp + u <= f && !visited[temp + u])
		{
			visited[temp + u] = true;
			q.push(make_pair(temp + u, level));
		}
		if (temp - d >= 1 && !visited[temp - d])
		{
			visited[temp - d] = true;
			q.push(make_pair(temp - d, level));
		}
		
	}
	return -1;
}

int main(void)
{
	cin >> f >> s >> g >> u >> d;

	if (s == g) printf("0");
	else
	{
		int res = bfs(s);
		if (res != -1) printf("%d", res);
		else printf("use the stairs");
	}
	return 0;
}