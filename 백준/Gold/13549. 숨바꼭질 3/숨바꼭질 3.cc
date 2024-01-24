#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100001] = { false, };

int main()
{
	int n, k, level = -1, qsize, t;
	bool solve = false;
	queue<int> q;
	cin >> n >> k;
	if (n > k) {
		printf("%d", n - k);
		return 0;
	}
	visited[n] = true;
	if (n == 0) q.push(n);
	else {
		for (int i = n; i <= 100000; i *= 2) {
			q.push(i);
			visited[i] = true;
			if (i == k) {
				printf("0");
				return 0;
			}
		}
	}
	while (!q.empty()) {
		level++;
		qsize = q.size();
		//printf("\n");
		while (qsize--) {
			n = q.front();
			//printf("%d\n", n);
			q.pop();
			if (n == k) {
				solve = true;
				break;
			}
			if (n + 1 <= k) {
				for (int i = n + 1; i <= 100000; i *= 2) {
					if (!visited[i]) {
						q.push(i);
						visited[i] = true;
					}
					else break;
				}
			}
			if (n - 1 >= 0) {
				if (n - 1 == 0) {
					if (!visited[n - 1]) {
						if (n - 1 == k) {
							solve = true;
							break;
						}
						q.push(n - 1);
						visited[n - 1] = true;
					}
				}
				for (int i = n - 1; i <= 100000; i *= 2) {
					if (!visited[i]) {
						q.push(i);
						visited[i] = true;
					}
					else break;
				}
			}
			if (solve) break;
		}
		if (solve) break;
	}
	printf("%d", level);
	return 0;
}