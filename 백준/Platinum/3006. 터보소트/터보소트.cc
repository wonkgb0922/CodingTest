#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int seg[400000], ary[100000];

int construct(int l, int r, int idx)
{
	if (l == r) seg[idx] = 1;
	else {
		int mid = (l + r) / 2;
		seg[idx] = construct(l, mid, idx * 2 + 1) + construct(mid + 1, r, idx * 2 + 2);
	}
	return seg[idx];
}

int update(int l, int r, int idx, int loc)
{
	if (loc < l || loc > r) return seg[idx];
	if (l == r) {
		if(l == loc) seg[idx] = 0;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = update(l, mid, idx * 2 + 1, loc) + update(mid + 1, r, idx * 2 + 2, loc);
	}
	return seg[idx];
}

int sum(int start, int end, int l, int r, int idx)
{
	if (r < start || l > end) return 0;
	if (start <= l && r <= end) return seg[idx];
	int mid = (l + r) / 2;
	return sum(start, end, l, mid, idx * 2 + 1) + sum(start, end, mid + 1, r, idx * 2 + 2);
}

int main()
{
	int n, in, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		ary[in - 1] = i;
	}
	construct(0, n - 1, 0);
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			r = n - (i / 2) - 1;
			l = ary[r];
			update(0, n - 1, 0, l);
			printf("%d\n", sum(l, n - 1, 0, n - 1, 0));
		}
		else {
			r = i / 2;
			l = ary[r];
			update(0, n - 1, 0, l);
			printf("%d\n", sum(0, l, 0, n - 1, 0));
		}
	}
	return 0;
}