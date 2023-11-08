#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int p[4000001], n;

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] += p[b];
	p[b] = a;
}

void nearby(int x, int y, int t) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		int nt = (nx - 1) * n + ny;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
			//printf("%d %d, %d\n", nx, ny, find(nt));
			if (find(nt) != 0) {
				merge(t, nt);
			}
		}
	}
}

int main()
{
	int k, x, y, level = 0, qsize, prev = -1, cnt = 0;

	queue<int> q;
	//memset(p, -1, sizeof(p));
	scanf("%d %d", &n, &k);
	p[0] = -1;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		x--;
		q.push(x * n + y);
		if (prev == -1)
			prev = x * n + y;

		p[x * n + y] = -1;

		nearby(x +1, y, x * n + y);		
		/*else {
			merge(prev, x * n + y);
			prev = x * n + y;
		}*/
	}
	cnt = k;
	while (!q.empty()) {
		if (p[find(prev)] == -cnt) break;
		level++;
		qsize = q.size();
		while (qsize--) {
			int t = q.front();
			int cx = (t - 1) / n + 1, cy = (t - 1) % n + 1;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0];
				int ny = cy + dir[i][1];
				int nt = (nx - 1) * n + ny;
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
					if (find(t) == find(nt)) continue;
					else if(find(nt) == 0) {
						p[find(t)]--;
						p[nt] = find(t);
						cnt++;
					}
					else
						merge(t, nt);

					nearby(nx, ny, nt);
					q.push(nt);
				}
			}
			q.pop();
		}
	}
	cout << level;
}