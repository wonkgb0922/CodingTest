#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int p[1000];

int find(int n) {
	if (p[n] == n) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main()
{
	int n, w, c, v, in, in2, in3, res;
	multimap<int, pair<int, int>,greater<>> m;
	scanf("%d%d", &n, &w);
	scanf("%d%d", &c, &v);
	for (int i = 0; i < w; i++) {
		scanf("%d%d%d", &in, &in2, &in3);
		m.insert({ in3, {in,in2} });
	}
	for (int i = 0; i < n; i++)
		p[i] = i;
	auto iter = m.begin();
	while (find(c) != find(v)) {
		res = iter->first;
		merge(iter->second.first, iter->second.second);
		iter++;
	}
	cout << res;
}