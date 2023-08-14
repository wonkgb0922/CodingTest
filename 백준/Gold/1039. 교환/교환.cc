#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

queue<int> q;
//set<string> visited;
bool visited[1000001] = { false, };
int main()
{
	int in, next, length, pi, pj, vali, valj;
	int k, MAX = -1, qsize, val;

	cin >> in >> k;
	for (int i = 10, j = 1;; i *= 10, j++) {
		if (in / i == 0) {
			length = j;
			break;
		}
	}
	q.push(in);
	while (k > 0) {
		qsize = q.size();
		k--;
		if (!qsize) break;
		//visited = set<string>();
		fill(visited, visited + 1000001, false);
		while (qsize--) {
			in = q.front();
			q.pop();
			pi = 1;
			for (int i = 0; i < length; i++) {
				pj = pi * 10;
				for (int j = i + 1; j < length; j++) {
					vali = (in / pi) % 10;
					valj = (in / pj) % 10;
					//printf("valj : %d, i : %d, pi: %d, length : %d\n", valj, i, pi, length);
					if (vali == 0 && j == length - 1) continue;
					next = in;
					next -= vali * pi;
					next += valj * pi;
					next -= valj * pj;
					next += vali * pj;
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
					}
					pj *= 10;
				}
				pi *= 10;
			}
		}
	}
	while (!q.empty()) {
		val = q.front();
		if (MAX < val) MAX = val;
		q.pop();
	}
	cout << MAX;
	return 0;
}