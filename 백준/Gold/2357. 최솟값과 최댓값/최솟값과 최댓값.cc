#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100000], seg1[400000], seg2[400000];

int construct1(int start, int end, int idx)
{
	if (start == end) {
		seg1[idx] = a[start];
		return seg1[idx];
	}
	int mid = (start + end) / 2;
	seg1[idx] = min(construct1(start, mid, idx * 2 + 1), construct1(mid + 1, end, idx * 2 + 2));

	return seg1[idx];
}

int construct2(int start, int end, int idx)
{
	if (start == end) {
		seg2[idx] = a[start];
		return seg2[idx];
	}
	int mid = (start + end) / 2;
	seg2[idx] = max(construct2(start, mid, idx * 2 + 1), construct2(mid + 1, end, idx * 2 + 2));

	return seg2[idx];
}

int Min(int l, int r, int il, int ir, int idx)
{
	if (l > ir || r < il) return 10000000000;
	if (il <= l && ir >= r) return seg1[idx];
	int mid = (l + r) / 2;
	return min(Min(l, mid, il, ir, idx * 2 + 1), Min(mid + 1, r, il, ir, idx * 2 + 2));
}

int Max(int l, int r, int il, int ir, int idx)
{
	if (l > ir || r < il) return 1;
	if (il <= l && ir >= r) return seg2[idx];
	int mid = (l + r) / 2;
	return max(Max(l, mid, il, ir, idx * 2 + 1), Max(mid + 1, r, il, ir, idx * 2 + 2));
}

int main()
{
	int m, in1, in2;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	construct1(0, n - 1, 0);
	construct2(0, n - 1, 0);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &in1, &in2);
		printf("%d %d\n", Min(0, n - 1, in1 - 1, in2 - 1, 0), Max(0, n - 1, in1 - 1, in2 - 1, 0));
	}

	return 0;
}