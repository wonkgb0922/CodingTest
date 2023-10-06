#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

bool visited[201] = { false };

using namespace std;

int main() {
	queue<vector<int>> q;
	set<vector<int>> s;
	vector<int> v;
	int in, qsize, level = -1;
	for (int i = 0; i < 3; i++) {
		cin >> in;
		v.push_back(in);
	}
	s.insert({ 0,0,v[2] });
	q.push({ 0,0,v[2] });
	visited[v[2]] = true;
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			auto val(q.front());
			q.pop();
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					auto cop(val);
					if (i == j) continue;
					if (cop[i] > 0 && cop[j] < v[j]) {
						int temp = min(cop[i], v[j] - cop[j]);
						cop[i] -= temp;
						cop[j] += temp;
						if (s.count(cop) == 0) {
							s.insert(cop);
							if(cop[0] == 0) visited[cop[2]] = true;
							q.push(cop);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 200; i++) {
		if (visited[i]) printf("%d ", i);
	}
	return 0;
}