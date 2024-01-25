#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int f, s, g, u, d;
bool visited[1000001] = { false };

int bfs(int num)
{
	queue<int> q;
	int level = -1, qsize;
	q.push(num);
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			auto t = q.front();
			q.pop();
			if (t == g || t == g) return level;\
			if (t + u <= f && !visited[t + u]) {
				visited[t + u] = true;
				q.push(t + u);
			}
			if (t - d >= 1 && !visited[t - d]) {
				visited[t - d] = true;
				q.push(t - d);
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> f >> s >> g >> u >> d;

	if (s == g) printf("0");
	else
	{
		int res = bfs(s);
		if (res != -1) printf("%d", res);
		else printf("use the stairs");
	}
	return 0;
}