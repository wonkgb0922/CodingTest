#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<short, pair<short,short>>> q;
bool visited[100][100][100] = {false,};
int ary[100][100][100] = {0,};
const short dir[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };

int main()
{
	int h, n, m, level = -1, cnt = 0, qsize;
	short f, s, z, nextZ, nextF, nextS;
	cin >> m >> n >> h;
	for (short i = 0; i < h; i++) {
		for (short j = 0; j < n; j++) {
			for (short k = 0; k < m; k++) {
				scanf("%d", &ary[i][j][k]);
				if (ary[i][j][k] == 1) {
					q.push({ i, {j,k} });
					visited[i][j][k] = true;
				}
				else if (!ary[i][j][k]) cnt++;
			}

		}
	}
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			z = q.front().first;
			f = q.front().second.first;
			s = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nextZ = z + dir[i][0];
				nextF = f + dir[i][1];
				nextS = s + dir[i][2];
				
				if (nextF >= 0 && nextF < n && nextS >= 0 && nextS < m && nextZ >= 0 && nextZ < h) {
					if (!ary[nextZ][nextF][nextS] && !visited[nextZ][nextF][nextS]) {
						cnt--;
						q.push({ nextZ, {nextF,nextS } });
						visited[nextZ][nextF][nextS] = true;
					}
				}
			}
		}
	}
	if (cnt == 0) printf("%d", level);
	else printf("-1");
	return 0;
}