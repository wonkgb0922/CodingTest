#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, in;
	priority_queue<int, vector<int>, greater<int>> q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &in);
			q.push(in);		
		}
		while (q.size() > n) q.pop();
	}
	printf("%d", q.top());

	return 0;
}