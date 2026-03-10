#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int a, b, level = 0, qsize;
	long long val;
	bool d = false;
	queue<int> q;
	scanf("%d%d", &a, &b);
	q.push(a);
	while (!q.empty()) {
		qsize = q.size();
		level++;
		while (qsize--) {
			val = q.front();
			q.pop();
			if (val == b) {
				d = true;
				break;
			}
			if (val * 2 <= b) q.push(val * 2);
			if (val * 10 + 1 <= b) q.push(val * 10 + 1);
		}
		if (d) break;
	}
	if (d) cout << level;
	else cout << -1;

	return 0;
}