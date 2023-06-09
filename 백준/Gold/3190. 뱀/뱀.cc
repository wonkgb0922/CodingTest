#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <memory.h>

using namespace std;

int map[102][102] = {0, };

int main()
{
	list<pair<int, int>> snake;
	queue<pair<int, char>> task;
	pair<int, int> f, temp, temp2;
	int n, k, l, in1, in2, cnt = 0;
	bool end = false;
	char in3;
	int state = 0;	// 오: 0, 아래: 1, 왼: 2, 위:3
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &in1, &in2);
		map[in1][in2] = 2;	// 2가 사과
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		scanf("%d %c", &in1, &in3);
		task.push({in1, in3});
	}
	snake.push_back({ 1,1 });
	map[1][1] = 1;
	while (!task.empty() && !end)
	{
		f = task.front();

		while (cnt < f.first)
		{
			cnt++;
			temp = snake.front();	// 꼬리
			temp2 = snake.back();	// 머리
			if (state == 0)
				temp2.second++;
			else if (state == 1)
				temp2.first++;
			else if (state == 2)
				temp2.second--;
			else
				temp2.first--;

			if (temp2.first <= 0 || temp2.second <= 0 || temp2.first > n|| temp2.second > n
				|| map[temp2.first][temp2.second] == 1)	// 벽 혹은 몸통에 부딫혔다?
			{
				end = true;
				break;
			}
			else if (map[temp2.first][temp2.second] == 2)	// 사과다?
			{}
			else
			{
				map[temp.first][temp.second] = 0;
				snake.pop_front();
			}
			map[temp2.first][temp2.second] = 1;
			snake.push_back(temp2);
		}
		if (f.second == 'D') state = (state + 1) % 4;
		else
		{
			state--;
			if (state < 0) state = 3;
		}
		if (end) break;
		task.pop();
	}
	if (task.empty())
	{
		while(true)
		{
			cnt++;
			temp = snake.front();	// 꼬리
			temp2 = snake.back();	// 머리
			if (state == 0)
				temp2.second++;
			else if (state == 1)
				temp2.first++;
			else if (state == 2)
				temp2.second--;
			else
				temp2.first--;

			if (temp2.first <= 0 || temp2.second <= 0 || temp2.first > n || temp2.second > n
				|| map[temp2.first][temp2.second] == 1)	// 벽 혹은 몸통에 부딫혔다?
				break;
			else if (map[temp2.first][temp2.second] == 2)	// 사과다?
			{}
			else
			{
				map[temp.first][temp.second] = 0;
				snake.pop_front();
			}
			map[temp2.first][temp2.second] = 1;
			snake.push_back(temp2);
		}
	}
	cout << cnt;
	return 0;
}
