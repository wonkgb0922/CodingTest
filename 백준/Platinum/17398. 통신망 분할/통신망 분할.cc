#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int p[100001];
int pass[100001];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] += p[b];
	p[b] = a;
}

int main()
{
	int n, m, q, in, in2;
	unsigned long long res = 0;
	vector<pair<int, int>> v;
	vector<int> r;
	memset(p, -1, sizeof(p));
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in, &in2);
		v.push_back({ in,in2 });
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &in);
		in--;
		pass[in] = 1;
		r.push_back(in);
	}
	reverse(r.begin(), r.end());
	for (int i = 0; i < m; i++) {
		if (!pass[i]) {
			merge(v[i].first, v[i].second);
		}
	}
	for (auto& it : r) {
		if (find(v[it].first) != find(v[it].second)) {
			res += p[find(v[it].first)] * p[find(v[it].second)];
			merge(v[it].first, v[it].second);
		}
	}
	cout << res;
}