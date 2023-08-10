#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

const int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0 } };
queue<string> q;
set<string> visited;

int main()
{
	int in, level = -1, qsize, pos, posx, posy, nx, ny;
	string temp = "", next;
	bool sol = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &in);
		temp += '0' + in;
	}
	q.push({ temp , 0 });
	visited.insert(temp);

	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			temp = q.front();
			if (temp == "123456780") {
				printf("%d", level);
				return 0;
			}
			q.pop();
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
						q.push(next);
					}
				}
			}
		}
		
	}
	printf("-1");
	return 0;
}