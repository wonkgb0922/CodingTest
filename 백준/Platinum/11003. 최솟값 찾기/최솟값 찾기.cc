#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

	int n, l, input;

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		q.push({ input , i });

		auto t = q.top();
		while (q.top().second <= i - l) q.pop();
		printf("%d ", q.top());
	}
}