#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, string>> q;
bool visited[10000] = {false, };

int main()
{
	int t, a, b, n, temp, d;
	string com;
	bool sol;
	cin >> t;
	while (t--) {
		scanf("%d%d", &a, &b);
		sol = false;
		q = queue<pair<int, string>>();
		fill_n(visited, 10000, false);
		visited[a] = true;
		q.push({ a, "" });
		while (!q.empty()) {
			n = q.front().first;
			com = q.front().second;
			q.pop();
			if (n == b) {
				sol = true;
				break;
			}
			temp = (2 * n) % 10000;
			if (!visited[temp]) {
				q.push({ temp, com + 'D'});
				visited[temp] = true;
			}
			temp = n - 1;
			if (temp < 0) temp = 9999;
			if (!visited[temp]) {
				q.push({ temp, com + 'S' });
				visited[temp] = true;
			}
			d = n / 1000;
			temp = (n - d * 1000) * 10 + d;
			//printf("%d를 L 한 결과 : %d\n", n, temp);
			if (!visited[temp]) {
				q.push({ temp, com + 'L' });
				visited[temp] = true;
			}
			d = n % 10;
			temp = (n / 10) + d * 1000;
			if (!visited[temp]) {
				q.push({ temp, com + 'R' });
				visited[temp] = true;
			}
		}
		if (sol) cout << com << '\n';
	}
	return 0;
}