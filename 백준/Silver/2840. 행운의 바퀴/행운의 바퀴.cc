#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int main()
{
	int n, k, i;
	char ary[26];
	int in1;
	char in2;
	bool visited[27];
	stack<pair<int, char>> s;
	memset(ary, '?', sizeof(char) * 26);
	memset(visited, false, sizeof(bool) * 27);

	cin >> n >> k;
	for (i = 0; i < k; i++)
	{
		scanf("%d %c", &in1, &in2);
		s.push({ in1, in2 });
	}
	i = 0;
	while (!s.empty())
	{
		in1 = s.top().first;
		in2 = s.top().second;
		s.pop();
		if (ary[i] == '?')
		{
			if (!visited[in2 - 65])
			{
				visited[in2 - 65] = true;
				ary[i] = in2;
			}
			else
			{
				printf("!");
				return 0;
			}
		}
		else
		{
			if (ary[i] != in2)
			{
				//cout << ary[i] << " " << in2 << endl;
				printf("!");
				return 0;
			}
		}
		i = (i + in1) % n;
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", ary[i]);
	}
	return 0;
}
