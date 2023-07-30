#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
bool visited[100001] = {false, };

int main()
{
	int n, k, level = -1, qsize;
	bool solve = false;
	cin >> n >> k;
	
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		level++;
		qsize = q.size();
		while (qsize--) {
			n = q.front();
			q.pop();
			if (n == k) {
				solve = true;
				break;
			}
			if (n + 1 <= k) {
				if (!visited[n + 1]) {
					q.push(n + 1);
					visited[n + 1] = true;
				}
			}
			if (n - 1 >= 0) {
				if (!visited[n - 1]) {
					q.push(n - 1);
					visited[n - 1] = true;
				}
			}
			if (n * 2 < 100001) {
				if (!visited[n * 2]) {
					q.push(n * 2);
					visited[n * 2] = true;
				}
			}
		}
		if (solve) break;
	}
	printf("%d", level);
	return 0;
}