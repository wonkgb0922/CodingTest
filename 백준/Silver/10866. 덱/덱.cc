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
			cin >> in2;
			q.push_front(in2);
		}
		else if (in1 == "push_back") {
			cin >> in2;
			q.push_back(in2);
		}
		else if (in1 == "pop_front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (in1 == "pop_back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
				q.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (in1 == "size") cout << q.size() << '\n';
		else if (in1 == "empty") cout << q.empty() << '\n';
		else if (in1 == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (in1 == "back") {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}