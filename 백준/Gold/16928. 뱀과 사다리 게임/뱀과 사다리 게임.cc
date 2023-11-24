#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool visited[101];

int main()
{
	int n, m, in, in2, qsize, level = -1;
	bool sol = false;
	map<int, int> la, sn;
	queue<int> q;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &in, &in2);
		la.insert({ in, in2 });
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in, &in2);
		sn.insert({ in, in2 });
	}
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			int pos = q.front();
			if (pos == 100) {
				sol = true;
				break;
			}
			for (int i = 1; i < 7; i++) {
				if (pos + i < 101) {
					auto rg = la.find(pos + i);
					if (rg != la.end()) {
						if (!visited[rg->second]) {
							visited[rg->second] = true;
							q.push(rg->second);
						}
					}
					else {
						rg = sn.find(pos + i);
						if (rg != sn.end()) {
							if (!visited[rg->second]) {
								visited[rg->second] = true;
								q.push(rg->second);
							}
						}
						else if (!visited[pos + i])
							q.push(pos + i);
					}
					visited[pos + i] = true;
				}				
			}
			q.pop();
		}
		if (sol)break;
	}
	cout << level;


	return 0;
}