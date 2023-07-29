#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<short, short>> q;
bool visited[1000][1000] = {false, };
int ary[1000][1000] = { 0, };
const short dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main()
{
	int n, m, level = -1, cnt = 0, qsize;
	short f, s, nextF, nextS;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ary[i][j]);
			if (ary[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
			}
			else if (ary[i][j] == 0) cnt++;
		}
	}
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			f = q.front().first;
			s = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nextF = f + dir[i][0];
				nextS = s + dir[i][1];
				if (nextF >= 0 && nextF < n && nextS >= 0 && nextS < m) {
					if (ary[nextF][nextS] == 0 && !visited[nextF][nextS]) {	
						cnt--;
						q.push({ nextF,nextS });
						visited[nextF][nextS] = true;
					}
				}
			}
		}
	}
	if (cnt == 0) printf("%d", level);
	else printf("-1");
	return 0;
}