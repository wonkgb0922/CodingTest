#include <stdio.h>	
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int ary[1000][1000];
int ans[1000][1000];
bool visited[1000][1000];

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
	memset(ans, -1, sizeof(ans));
	int n, m, level = 0;
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ary[i][j]);
			if (ary[i][j] == 2) {
				q.push({ i, j });
				visited[i][j] = true;
			}
			else if (ary[i][j] == 0) ans[i][j] = 0;
		}
	}
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			auto t = q.front();
			q.pop();
			ans[t.first][t.second] = level;
			for (int i = 0; i < 4; i++) {
				int ni = t.first + dir[i][0];
				int nj = t.second + dir[i][1];

				if (0 <= ni && ni < n && 0 <= nj && nj < m) {
					if (!visited[ni][nj] && ary[ni][nj] != 0) {
						q.push({ ni, nj });
						visited[ni][nj] = true;
					}
				}
			}
		}
		level++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}