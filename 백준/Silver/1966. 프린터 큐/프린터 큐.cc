#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

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
			if (q2.top() == q.front().second) {
				cnt++;
				q2.pop();
				if (q.front().first == m) break;
			}
			else q.push({ q.front().first, q.front().second});
			q.pop();
		}
		printf("%d\n", cnt);
		q = queue<pair<int,int>>();
		q2 = priority_queue<int>();
	}
	return 0;
}