#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int n;
string ary[100];
bool visited[101][101] = { false };
int res1 = 0, res2 = 0;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			if (!visited[ny][nx]) {
				if (ary[y][x] == ary[ny][nx])
					dfs(ny, nx);
				else
					q.push({ ny, nx });
			}			
		}
	}
}
void dfs2(int y, int x)	// 색약 dfs
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			if (!visited[ny][nx]) {
				if ((ary[y][x] == ary[ny][nx]) || (ary[y][x] == 'G' && ary[ny][nx] == 'R') || (ary[y][x] == 'R' && ary[ny][nx] == 'G'))
					dfs2(ny, nx);
				else
					q.push({ ny, nx });
			}
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	q.push({ 0,0 });
	while (!q.empty()) {
		auto stt = q.front();
		q.pop();
		if (visited[stt.first][stt.second]) continue;
		dfs(stt.first, stt.second);
		res1++;
	}
	memset(visited, false, sizeof(visited));
	q.push({ 0,0 });

	while (!q.empty()) {
		auto stt = q.front();
		q.pop();
		if (visited[stt.first][stt.second]) continue;
		dfs2(stt.first, stt.second);
		res2++;
	}
	printf("%d %d", res1, res2);
	return 0;
}