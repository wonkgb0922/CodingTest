#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int p[200];

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
	int n, m, in, res = -1;
	scanf("%d%d", &n, &m);
	memset(p, -1, sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &in);
			if (in)
				merge(i, j);
		}
	}
	while (m--) {
		scanf("%d", &in);
		if (res == -1)
			res = find(in - 1);
		else {
			if (res != find(in - 1)) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}