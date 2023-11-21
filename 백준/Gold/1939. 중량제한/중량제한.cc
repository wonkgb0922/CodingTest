#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int p[10001];

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
	int n, m, in, in2, in3, res;
	multimap<int, pair<int, int>, greater<>> mm;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &in, &in2, &in3);
		mm.insert({ in3, {in,in2} });
	}
	for (int i = 0; i < n; i++)
		p[i] = i;
	scanf("%d%d", &in, &in2);
	auto iter = mm.begin();
	while (find(in) != find(in2)) {
		res = iter->first;
		merge(iter->second.first, iter->second.second);
		iter++;
	}
	cout << res;
}