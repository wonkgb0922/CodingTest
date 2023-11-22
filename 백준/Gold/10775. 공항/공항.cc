#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int p[100001];

int find(int n) {
	if (p[n] == n) return n;
	p[n] = find(p[n]);
	return p[n];
}

int main()
{
	int g, m, in, cnt = 0;
	scanf("%d%d", &g, &m);
	for (int i = 1; i <= g; i++)
		p[i] = i;
	while (m--) {
		scanf("%d", &in);
		if (find(in) == 0) break;
		else {
			cnt++;
			p[find(in)] = find(find(in) - 1);
		}
	}
	printf("%d", cnt);
}