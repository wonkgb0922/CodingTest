#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

int main()
{
	int n, m, cnt = 0, lcnt, rcnt;
	int input;
	int ary[51];
	list<int> dq, cp;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		scanf("%d", &ary[i]);

	for (int i = 0; i < n; i++)
		dq.push_back(i + 1);

	for(int i = 0; i < m ; i++)
	{
		lcnt = 0;
		rcnt = 0;
		cp = dq;
		while (cp.front() != ary[i])
		{
			input = cp.front();
			cp.pop_front();
			cp.push_back(input);
			lcnt++;
		}
		cp = dq;
		while (cp.front() != ary[i])
		{
			input = cp.back();
			cp.pop_back();
			cp.push_front(input);
			rcnt++;
		}
		dq = cp;
		dq.pop_front();
		cnt += min(lcnt, rcnt);
	}
	cout << cnt;

	return 0;
}
