#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, in2;
	string in1;
	queue<int> q;

	cin >> n;
	while (n--) {
		cin >> in1;
		if (in1 == "push") {
			cin >> in2;
			q.push(in2);
		}
		else if (in1 == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (in1 == "size")
			cout << q.size() << '\n';
		else if (in1 == "empty")
			cout << q.empty() << '\n';
		else if (in1 == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (in1 == "back") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
	return 0;
}