#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
bool visited[100000] = {false, };

int main()
{
	int n, t, g, level = -1, qsize, dec;
	bool sol = false;
	cin >> n >> t >> g;

	visited[n] = true;
	q.push(n);
	t++;
	while (t--) {
		level++;
		qsize = q.size();
		while (qsize--) {
			n = q.front();
			q.pop();
			dec = 10;
			if (n == g) {
				sol = true;
				break;
			}
			if (n + 1 <= g) {
				if (!visited[n + 1]) {
					visited[n + 1] = true;
					q.push(n + 1);
				}
			}
			n *= 2;
			if (n < 100000) {
				while (n / dec != 0) dec *= 10;
				dec /= 10;
				n -= dec;
				if (n < 0) n = 0;
				if (!visited[n]) {
					visited[n] = true;
					q.push(n);
				}
			}

		}
		if (sol) break;
	}
	if (sol) printf("%d", level);
	else printf("ANG");
	
	return 0;
}