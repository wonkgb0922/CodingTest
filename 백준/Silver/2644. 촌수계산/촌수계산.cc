#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

bool visited[101] = { false, };

int main()
{
	int n, m, temp, qsize;
	int s, e, in1, in2, res = 1;
	multimap<int, int> mm;
	queue<int> q;
	cin >> n;
	cin >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in1, &in2);
		mm.insert({ in1,in2 });
		mm.insert({ in2,in1 });
	}
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		qsize = q.size();
		for(int i = 0; i < qsize; i++) {
			temp = q.front();
			q.pop();
			auto range = mm.equal_range(temp);
			for (auto& it = range.first; it != range.second; it++) {
				if (!visited[it->second]) {
					if (it->second == e) {
						printf("%d", res);
						return 0;
					}
					visited[it->second] = true;
					q.push(it->second);
				}
			}
		}
		res++;
	}
	printf("-1");
	return 0;
}