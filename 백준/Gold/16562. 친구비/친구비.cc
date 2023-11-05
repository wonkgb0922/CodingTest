#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int p[10000];
bool visited[10000];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = max(p[a], p[b]);
	p[b] = a;
}

int main()
{
	int n, m, k, in, in2, res = 0;

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		p[i] = -in;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in, &in2);
		merge(in - 1, in2 - 1);
	}
	for (int i = 0; i < n; i++) {
		int t = find(i);
		if (!visited[t]) {
			res += -(p[t]);
			visited[t] = true;
		}
	}
	if (res <= k) printf("%d", res);
	else printf("Oh no");
	return 0;
}