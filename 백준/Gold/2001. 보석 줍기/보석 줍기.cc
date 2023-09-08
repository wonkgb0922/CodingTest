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
	int in, pos, state, ccnt, qsize, res = 0;
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
		qsize = q.size();
		while (qsize--) {
			pos = q.front().first;
			state = q.front().second.first;
			ccnt = q.front().second.second;
			q.pop();
			if (pos == 1 && res <= ccnt) {
				res = ccnt;
				if (cr.find(1) != cr.end()) {
					if (!(state & (1 << cr[1]))) res++;
				}
			}

			for (int i = 0; i < weight[pos].size(); i++) {
				if (cr.find(pos) != cr.end()) {
					if (weight[pos][i].second >= ccnt + 1) {
						if (!visited[weight[pos][i].first][state | (1 << cr[pos])]){
							visited[weight[pos][i].first][state | (1 << cr[pos])] = true;
							if (state & (1 << cr[pos]))
								q.push({ weight[pos][i].first, {state | (1 << cr[pos]), ccnt} });
							else q.push({ weight[pos][i].first, {state | (1 << cr[pos]), ccnt + 1} });
						}
					}
				}
				if (weight[pos][i].second >= ccnt) {
					if (!visited[weight[pos][i].first][state]) {
						visited[weight[pos][i].first][state] = true;
						q.push({ weight[pos][i].first, {state, ccnt} });
					}
				}
			}
		}
	}
	std::cout << res;
	return 0;
}