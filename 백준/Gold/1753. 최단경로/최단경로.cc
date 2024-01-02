#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000

using namespace std;

vector<pair<int,int>> weight[20000];
int res[20000];

int main()
{
	int v, e, k, in1, in2, in3;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
	scanf("%d%d", &v, &e);
	scanf("%d", &k);
	k--;
	for (int i = 0; i < v; i++)
		res[i] = INF;
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &in1, &in2, &in3);
		weight[in1 - 1].push_back({ in2 - 1,in3 });
	}
	res[k] = 0;
	pq.push({ 0, k });

	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		for (auto& it : weight[t.second]) {
			if (res[it.first] > res[t.second] + it.second) {
				res[it.first] = res[t.second] + it.second;
				pq.push({ res[it.first], it.first });
			}
		}
	}
	for (int i = 0; i < v; i++) {
		if (res[i] == INF) printf("INF\n");
		else printf("%d\n", res[i]);
	}
	return 0;
}