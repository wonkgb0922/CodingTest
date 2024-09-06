#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, ary[1000][1000];
int dir[8][2] = { {0,1} , {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1} };
bool visited[1000][1000];

bool isCollapse(int i, int j)
{
	int cnt = 0;
	for (int k = 0; k < 8; k++) {
		int ik = i + dir[k][0];
		int jk = j + dir[k][1];
		if (ik >= 0 && ik < n && jk >= 0 && jk < m) {
			if (!ary[ik][jk]) cnt++;
		}
	}
	if (cnt >= ary[i][j]) return true;
	return false;
}

int main()
{
	queue<pair<int, int >> q;
	int qsize, level = 0;
	scanf("%d%d", &n, &m);
	char in;
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &in);
			if (in == '.') ary[i][j] = 0;
			else ary[i][j] = in - '0';
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ary[i][j] && isCollapse(i, j)) {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			auto t = q.front();
			ary[t.first][t.second] = 0;
			for (int k = 0; k < 8; k++) {
				int ik = t.first + dir[k][0];
				int jk = t.second + dir[k][1];
				if (ary[ik][jk] && isCollapse(ik, jk) && !visited[ik][jk]) {
					visited[ik][jk] = true;
					q.push({ ik, jk });
				}
			}
			q.pop();
		}
	}
	cout << level;

}