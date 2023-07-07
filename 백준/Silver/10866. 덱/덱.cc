#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	deque<int> q;
	int n;
	string in1;
	int in2;

	cin >> n;
	while (n--)
	{
		cin >> in1;
		if (in1 == "push_front") {
			scanf("%d", &in2);
			q.push_front(in2);
		}
		else if (in1 == "push_back") {
			scanf("%d", &in2);
			q.push_back(in2);
		}
		else if (in1 == "pop_front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (in1 == "pop_back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
				q.pop_back();
			}
			else printf("-1\n");
		}
		else if (in1 == "size") printf("%d\n", q.size());
		else if (in1 == "empty") printf("%d\n", q.empty());
		else if (in1 == "front") {
			if (!q.empty()) printf("%d\n", q.front());
			else cout << -1 << '\n';
		}
		else if (in1 == "back") {
			if (!q.empty()) printf("%d\n", q.back());
			else printf("-1\n");
		}
	}
	return 0;
}