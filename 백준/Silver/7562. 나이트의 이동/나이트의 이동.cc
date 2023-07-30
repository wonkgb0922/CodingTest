#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<short, short>> q;
bool visited[1000][1000] = {false, };
const short dir[8][2] = { {1,2}, {2,1}, {2,-1}, {1,-2},
						{-1,2}, {-2,1}, {-2,-1}, {-1,-2} };

int main()
{
	int t, n, x1, y1, x2, y2, tx, ty, level, qsize;
	bool solve;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		scanf("%d%d", &x1, &y1);
		scanf("%d%d", &x2, &y2);
		q = queue<pair<short, short>>();
		q.push({ x1, y1 });
		fill_n(&visited[0][0], 1000 * 1000, false);
		visited[y1][x1] = true;
		level = -1;
		solve = false;
		while (!q.empty()) {
			qsize = q.size();
			level++;
			while (qsize--) {
				x1 = q.front().first;
				y1 = q.front().second;
				q.pop();
				if (x1 == x2 && y1 == y2) {
					solve = true;
					break;
				}
				for (int i = 0; i < 8; i++) {
					tx = x1 + dir[i][0];
					ty = y1 + dir[i][1];
					if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
						if (!visited[ty][tx]) {
							q.push({ tx,ty });
							visited[ty][tx] = true;
						}
					}
				}
			}
			if (solve) break;
		}
		printf("%d\n", level);
		
	}
	return 0;
}