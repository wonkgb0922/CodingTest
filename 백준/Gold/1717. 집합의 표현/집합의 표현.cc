#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int p[1000001];

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
	int n, m, in, a, b;
	scanf("%d%d", &n, &m);
	//memset(p, -1, sizeof(int)*n);
	for (int i = 0; i <= n; i++)
		p[i] = -1;
	while (m--) {
		scanf("%d%d%d", &in, &a, &b);
		if (in) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else
			merge(a, b);
	}
	return 0;
}