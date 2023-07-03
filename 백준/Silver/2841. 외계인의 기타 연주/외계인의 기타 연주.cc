#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<int> s[6];
	int n, p;
	int cnt = 0;
	int in1, in2;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &in1, &in2);
		if (!s[in1 - 1].empty())
		{
			
			while (!s[in1 - 1].empty())
			{
				if (s[in1 - 1].top() <= in2) break;
				s[in1 - 1].pop();
				cnt++;
			}
			if (!s[in1 - 1].empty())
			{
				if (s[in1 - 1].top() < in2)
				{
					s[in1 - 1].push(in2);
					cnt++;
				}
			}
			else {
				s[in1 - 1].push(in2);
				cnt++;
			}
		}
		else
		{
			s[in1 - 1].push(in2);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}