#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int n, m;
string ary[100];
bool visited[101][101] = {false};

int bfs()
{
	queue<pair<pair<int,int>, int>> q;
	int level;
	int i, j;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0] = true;
	while (!q.empty())
	{
		i = q.front().first.first;
		j = q.front().first.second;
		level = q.front().second + 1;
		q.pop();
		if (i == n - 1 && j == m - 1) return --level;
		if (i - 1 >= 0)
		{
			if (!visited[i - 1][j] && ary[i - 1][j] == '1')
			{
				visited[i - 1][j] = true;
				q.push(make_pair(make_pair(i-1, j), level));
			}
		}
		if (i + 1 < n)
		{
			if (!visited[i + 1][j] && ary[i + 1][j] == '1')
			{
				visited[i + 1][j] = true;
				q.push(make_pair(make_pair(i + 1, j), level));
			}
		}
		if (j - 1 >= 0)
		{
			if (!visited[i][j - 1] && ary[i][j - 1] == '1')
			{
				visited[i][j - 1] = true;
				q.push(make_pair(make_pair(i, j - 1), level));
			}
		}
		if (j + 1 < m)
		{
			if (!visited[i][j + 1] && ary[i][j + 1] == '1')
			{
				visited[i][j + 1] = true;
				q.push(make_pair(make_pair(i, j + 1), level));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}
	printf("%d", bfs());
	return 0;
}