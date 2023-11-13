#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int p[50];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (b == 0) {
		p[b] += p[a];
		p[a] = b;
	}
	else {
		p[a] += p[b];
		p[b] = a;
	}
}

int main()
{
	int n, m, tcnt, pos, in, cnt = 0;
	bool d;
	vector<int> v;
	memset(p, -1, sizeof(p));
	scanf("%d%d", &n, &m);
	scanf("%d", &tcnt);
	for (int i = 0; i < tcnt; i++) {
		scanf("%d", &in);
		merge(0, in);
	}
	for (int i = 0; i < m; i++) {
		d = false;
		scanf("%d%d", &tcnt, &pos);
		for (int j = 1; j < tcnt; j++) {
			scanf("%d", &in);
			merge(pos, in);
		}
		v.push_back(pos);
	
	}
	for (auto& it : v)
		if (find(it) != 0) cnt++;
	cout << cnt;
}