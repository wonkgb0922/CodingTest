#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

bool visited[50][50][1 << 6] = { false, };
short dir[4][2] = { {0,1}, {0,-1}, {1,0},{-1,0} };

int main(void)
{
	queue<pair<pair<int, int>,int>> q;
	short n, m, x, y, key, qsize, level = -1;
	char ary[50][50];
	bool sol = false;
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &ary[i][j]);
			if (ary[i][j] == '0') {
				x = j;
				y = i;
			}
		}
		getchar();
	}
	q.push({ {x, y}, 0 });
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			x = q.front().first.first;
			y = q.front().first.second;
			key = q.front().second;
			visited[y][x][key] = true;
			q.pop();
			if (ary[y][x] == '1') {
				sol = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nextx = x + dir[i][1];
				int nexty = y + dir[i][0];

				if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
					int nextkey = key;
					if (ary[nexty][nextx] == '#') continue;
					if (ary[nexty][nextx] >= 'a' && ary[nexty][nextx] <= 'f')
						nextkey |= 1 << (ary[nexty][nextx] - 'a');
					else if (ary[nexty][nextx] >= 'A' && ary[nexty][nextx] <= 'F') {
						if (!(key & (1 << (ary[nexty][nextx] - 'A')))) continue;
					}
					if (!visited[nexty][nextx][nextkey]) {
						visited[nexty][nextx][nextkey] = true;
						q.push({ {nextx, nexty}, nextkey });
					}
				}
			}
		}
		if (sol) break;
	}
	if (sol) cout << level;
	else cout << -1;
	return 0;
}