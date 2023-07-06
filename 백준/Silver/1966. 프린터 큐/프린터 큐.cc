#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.first == p2.first) return p1.second > p2.second;
		return p1.first < p2.first;
	}
};

int main()
{
	int t, n, m, in, cnt, max;
	queue<pair<int,int>> q;
	priority_queue<int> q2;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d", &n, &m);
		cnt = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &in);
			q.push({ i, in});
			q2.push(in);
		}
		while (!q.empty())
		{
			int idx = q.front().first;
			int value = q.front().second;
			q.pop();

			if (q2.top() == value) {
				cnt++;
				q2.pop();
				if (idx == m) break;
			}
			else q.push({ idx, value });
		}
		printf("%d\n", cnt);
		q = queue<pair<int,int>>();
		q2 = priority_queue<int>();
	}
	return 0;
}