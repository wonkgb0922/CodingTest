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
	int n, input;
	list<pair<int,int>> q;
	vector<int> res;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		q.push_back({ input, i + 1 });
	}
	while (1)
	{
		res.push_back(q.front().second);
		input = q.front().first;
		q.pop_front();
		if (q.empty())break;
		if (input > 0)
		{
			while (--input >= 1)
			{
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else
		{
			while (input++ != 0)
			{
				q.push_front(q.back());
				q.pop_back();
			}
		}
	}
	for (auto& it : res) printf("%d ", it);

	return 0;
}
