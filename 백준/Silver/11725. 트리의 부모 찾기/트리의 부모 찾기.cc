#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

multimap<int, int> m1;
bool visited[100001] = { false };
int res[100001] = { 0 };

int main(void)
{
	int n, in, in2;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &in, &in2);
		m1.insert({ in, in2 });
		m1.insert({ in2, in });
	}
	queue<pair<int, int>> q;
	int temp = 0;

	q.push({1,0});
	while (!q.empty()) {
		res[q.front().first] = q.front().second;
		temp = q.front().first;
		q.pop();

		auto range = m1.equal_range(temp);
		for (auto& it = range.first; it != range.second; it++) {
			if (!visited[it->second]) {
				visited[it->second] = true;
				q.push({ it->second, temp });
			}
		}
	}
	for (int i = 2; i <= n; i++)
		printf("%d\n", res[i]);
	return 0;
}