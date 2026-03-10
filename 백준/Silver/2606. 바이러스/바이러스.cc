#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include <map>
#include <queue>
using namespace std;

multimap<int, int> mm;
queue<int> q;
bool visited[101] = {false };
int main()
{
	int n, m, in1, in2, cnt = -1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in1, &in2);
		mm.insert({ in1, in2 });
		mm.insert({ in2, in1 });
	}
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		cnt++;
		in1 = q.front();
		q.pop();
		auto rg = mm.equal_range(in1);
		for (auto& it = rg.first; it != rg.second; it++) {
			if (!visited[it->second]) {
				visited[it->second] = true;
				q.push(it->second);
			}
		}
	}
	cout << cnt;

	return 0;
}