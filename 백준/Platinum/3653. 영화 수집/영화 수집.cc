#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int seg[800000], t, n, m, ary[100001], maxLen;

int construct(int l, int r, int idx)
{
	if (l == r) {
		if (r < n) seg[idx] = 1;
		else seg[idx] = 0;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = construct(l, mid, idx * 2 + 1) + construct(mid + 1, r, idx * 2 + 2);
	}
	return seg[idx];
}

int update(int l, int r, int idx, int loc, int val)
{
	if (loc < l || loc > r) return seg[idx];
	if (l == r) {
		if (l == loc) seg[idx] = val;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = update(l, mid, idx * 2 + 1, loc, val) + update(mid + 1, r, idx * 2 + 2, loc, val);
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
	int in, in2;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		maxLen = max(n, m);
		construct(0, maxLen * 2 - 1, 0);
		for (int i = 1; i <= n; i++)
			ary[i] = n - i;

		for (int i = 0; i < m; i++) {
			scanf("%d", &in);
			in2 = ary[in];
			update(0, maxLen * 2 - 1, 0, in2, 0);
			printf("%d ", sum(in2, maxLen * 2 - 1, 0, maxLen * 2 - 1, 0));
			update(0, maxLen * 2 - 1, 0, n + i, 1);
			ary[in] = n + i;
		}
		printf("\n");
	}
	return 0;
}