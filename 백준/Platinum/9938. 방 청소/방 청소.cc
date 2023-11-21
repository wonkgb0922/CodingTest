#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int p[300001], m[300001];

int find(int n) {
	if (p[n] == n) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	p[b] = a;
	printf("LADICA\n");
}

int main()
{
	int n, l, in, in2;
	scanf("%d%d", &n, &l);
	for (int i = 0; i <= l; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &in, &in2);
		if (m[in] == 0) {
			m[in] = i;
			merge(in2, in);
		}
		else if (m[in2] == 0) {
			m[in2] = i;
			merge(in, in2);
		}
		else if (m[find(in)] == 0) {
			m[find(in)] = i;
			merge(in2, in);
		}
		else if (m[find(in2)] == 0) {
			m[find(in2)] = i;
			merge(in, in2);
		}
		else
			printf("SMECE\n");
	}
}