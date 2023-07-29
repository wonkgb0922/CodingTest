#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<pair<short, short>, short>> q;
int visited[2][1000][1000] = {0, };
string ary[1000];
const short dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main()
{
	int n, m, res = -1;
	bool solve = false;
	short f, s, isValid, nextF, nextS;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	q.push({ { 0,0 }, 1 });
	visited[0][0][0] = 1;
	visited[1][0][0] = 1;
	while (!q.empty()) {
		f = q.front().first.first;
		s = q.front().first.second;
		isValid = q.front().second;
		q.pop();
		if (f == n - 1 && s == m - 1) {
			res = visited[isValid][f][s];
			break;
		}
		for (int i = 0; i < 4; i++) {
			nextF = f + dir[i][0];
			nextS = s + dir[i][1];
			if (nextF >= 0 && nextF < n && nextS >= 0 && nextS < m) {
				//다음 칸이 벽이고 뚫을 수 있을 때
				if (ary[nextF][nextS] == '1' && isValid == 1) {
					q.push({ {nextF,nextS}, 0 });
					visited[isValid - 1][nextF][nextS] = visited[isValid][f][s] + 1;
				}
				//다음 칸이 0이고 방문하지 않았을 때
				else if (ary[nextF][nextS] == '0' && visited[isValid][nextF][nextS] == 0) {
					q.push({ {nextF,nextS},isValid });
					visited[isValid][nextF][nextS] = visited[isValid][f][s] + 1;
				}
			}
		}
	}
	cout << res;
	return 0;
}