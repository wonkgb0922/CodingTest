#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1001][1001];

int main()
{
	int n, level = -1, qsize;
	bool sol = false;
	queue<pair<int, int>> q;
	cin >> n;
	q.push({ 1,0 });
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			auto f = q.front().first;
			auto s = q.front().second;
			q.pop();
			if (f == n) {
				sol = true;
				break;
			}
			if (!visited[f][f]) {
				q.push({ f, f });
				visited[f][f] = true;
			}
			if (f + s < 1001 && !visited[f + s][s]) {
				q.push({ f + s, s });
				visited[f + s][s] = true;
			}
			if (f > 0 && !visited[f - 1][s]) {
				q.push({ f - 1, s });
				visited[f - 1][s] = true;
			}
		}
		if (sol) break;
	}
	cout << level;

	return 0;
}