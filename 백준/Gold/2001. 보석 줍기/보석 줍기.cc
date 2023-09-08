#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

bool visited[101][1 << 14] = { false, };
vector<pair<int,int>> weight[101];
map<int, int> cr;
int n, m, k;

int main(void)
{
	queue<pair<int, pair<int, int>>> q;
	int in, pos, state, ccnt, res = 0, next, val;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &in);
		cr[in] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &in, &pos, &state);
		weight[in].push_back({ pos, state });
		weight[pos].push_back({ in, state });
	}
	q.push({ 1, {0, 0} });
	visited[1][0] = true;
	while (!q.empty()) {
		pos = q.front().first;
		state = q.front().second.first;
		ccnt = q.front().second.second;
		q.pop();
		if (pos == 1 && res <= ccnt) {
			res = ccnt;
			if (cr.find(1) != cr.end())
				if (!(state & (1 << cr[1]))) res++;
		}
		for (int i = 0; i < weight[pos].size(); i++) {
			next = weight[pos][i].first;
			val = weight[pos][i].second;
			if (cr.find(pos) != cr.end()) {
				if (val >= ccnt + 1) {
					if (!visited[next][state | (1 << cr[pos])]){
						visited[next][state | (1 << cr[pos])] = true;
						if (state & (1 << cr[pos]))
							q.push({ next, {state | (1 << cr[pos]), ccnt} });
						else q.push({ next, {state | (1 << cr[pos]), ccnt + 1} });
					}
				}
			}
			if (val >= ccnt) {
				if (!visited[next][state]) {
					visited[next][state] = true;
					q.push({ next, {state, ccnt} });
				}
			}
		}
	}
	std::cout << res;
	return 0;
}