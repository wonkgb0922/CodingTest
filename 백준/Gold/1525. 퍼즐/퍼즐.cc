#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

const int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0 } };
queue<pair<string, int>> q;
set<string> visited;

int main()
{
	int in, count, pos, posx, posy, nx, ny;
	string temp = "", next;
	bool sol = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &in);
		temp += '0' + in;
	}
	q.push({ temp , 0 });
	visited.insert(temp);

	while (!q.empty()) {
		temp = q.front().first;
		count = q.front().second;
		q.pop();
		if (temp == "123456780") {
			printf("%d", count);
			return 0;
		}
		pos = temp.find('0');
		posx = pos % 3;
		posy = pos / 3;
		for (int i = 0; i < 4; i++) {
			nx = posx + dir[i][1];
			ny = posy + dir[i][0];
			if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2) {
				next = temp;
				swap(next[pos], next[ny * 3 + nx]);
				if (visited.find(next) == visited.end()) {
					visited.insert(next);
					q.push({ next, count + 1 });
				}
			}
		}
	}
	printf("-1");
	return 0;
}