#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100001];

int main()
{
	int n, k, level = -1, qsize;
	bool solve = false;
	queue<pair<int, vector<int>>> q;
	cin >> n >> k;
	if (n > k) {
		printf("%d\n", n - k);
		while (n >= k)
			printf("%d ", n--);
		return 0;
	}
	vector<int> v(100001);
	q.push({ n, {n} });
	visited[n] = true;
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			auto& r = q.front();
			n = r.first;
			v = r.second;
			q.pop();
			if (n == k) {
				solve = true;
				break;
			}
			if (n * 2 < 100001) {
				if (!visited[n * 2]) {
					v.push_back(n * 2);
					q.push({ n * 2 , v });
					v.pop_back();
					visited[n * 2] = true;
				}
			}
			if (n + 1 <= k) {
				if (!visited[n + 1]) {
					v.push_back(n + 1);
					q.push({ n + 1, v });
					v.pop_back();
					visited[n + 1] = true;
				}
			}
			if (n - 1 >= 0) {
				if (!visited[n - 1]) {
					v.push_back(n - 1);
					q.push({ n - 1 , v });
					v.pop_back();
					visited[n - 1] = true;
				}
			}
		}
		if (solve) break;
	}
	printf("%d\n", level);
	for (auto it : v)
		printf("%d ", it);
	return 0;
}