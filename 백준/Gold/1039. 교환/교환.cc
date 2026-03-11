#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

queue<string> q;
set<string> visited;

int main()
{
	string in, next;
	int k, MAX = -1, qsize, val;

	cin >> in >> k;
	q.push(in);
	while (k > 0) {
		qsize = q.size();
		k--;
		if (!qsize) break;
		visited = set<string>();
		while (qsize--) {
			in = q.front();
			q.pop();
			//cout << in << endl;
			for (int i = 0; i < in.length() - 1; i++) {
				for (int j = i + 1; j < in.length(); j++) {
					if (i == 0 && in[j] == '0') continue;
					next = in;
					swap(next[i], next[j]);
					if (visited.find(next) == visited.end()) {
						visited.insert(next);
						q.push(next);
					}
				}
			}
		}
	}
	while (!q.empty()) {
		val = stoi(q.front());

		if (MAX < val) MAX = val;
		q.pop();
	}
	cout << MAX;
	return 0;
}