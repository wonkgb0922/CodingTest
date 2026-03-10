#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> v, temp;

int main() {
	int n, k;
	queue<int> q;
	vector<int> res;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		res.push_back(q.front());
		q.pop();
	}
	printf("<");
	for (int i = 0; i < res.size(); i++) {
		printf("%d", res[i]);
		if (i != res.size() - 1) printf(", ");
	}
	printf(">");
	return 0;
}