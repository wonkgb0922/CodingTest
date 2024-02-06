#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[200][200];
int dir[6][2] = { {-2,-1},{-2,+1},{0,-2},{0,2},{2,-1},{2,1} };

int main()
{
	int n, r1, c1, r2, c2, qsize, level = -1;
	bool d = false;
	queue<pair<int, int>> q;

	cin >> n >> r1 >> c1 >> r2 >> c2;
	
	visited[r1][c1] = true;
	q.push({ r1,c1 });
	while (!q.empty() && !d) {
		qsize = q.size();
		level++;
		while (qsize--) {
			int a = q.front().first, b = q.front().second;
			q.pop();
			if (a == r2 && b == c2) {
				d = true;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int na = a + dir[i][0];
				int nb = b + dir[i][1];
				if (na >= 0 && na < n && nb >= 0 && nb < n) {
					if (!visited[na][nb]) {
						visited[na][nb] = true;
						q.push({ na, nb });
					}
				}
			}
		}
	}
	if (d) cout << level;
	else cout << -1;

	return 0;
}