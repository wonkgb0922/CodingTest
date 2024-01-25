#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

string ary[100];
bool visited[101][101] = { false };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main(void)
{
	int n, m, level = 0, qsize;
	bool sol = false;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	queue<pair<int, int>> q;
	q.push({0,0});
	visited[0][0] = true;
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			auto y = q.front().first;
			auto x = q.front().second;
			q.pop();
			if (y == n - 1 && x == m - 1) {
				sol = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
					if (!visited[ny][nx] && ary[ny][nx] == '1') {
						visited[ny][nx] = true;
						q.push({ny,nx});
					}
				}
			}
		}
		if (sol) break;
	}
	printf("%d", level);
	return 0;
}