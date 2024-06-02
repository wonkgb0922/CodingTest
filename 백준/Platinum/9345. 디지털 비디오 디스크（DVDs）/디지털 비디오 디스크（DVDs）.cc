#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int seg[400000], seg2[400000];

int construct(int l, int r, int idx)
{
	if (l == r) seg[idx] = l;
	else {
		int mid = (l + r) / 2;
		seg[idx] = min(construct(l, mid, idx * 2 + 1), construct(mid + 1, r, idx * 2 + 2));
	}
	return seg[idx];
}

int construct2(int l, int r, int idx)
{
	if (l == r) seg2[idx] = l;
	else {
		int mid = (l + r) / 2;
		seg2[idx] = max(construct2(l, mid, idx * 2 + 1), construct2(mid + 1, r, idx * 2 + 2));
	}
	return seg2[idx];
}

int update(int l, int r, int idx, int loc, int val)
{
	if (loc < l || loc > r) return seg[idx];
	if (l == r) {
		if (l == loc) seg[idx] = val;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = min(update(l, mid, idx * 2 + 1, loc, val), update(mid + 1, r, idx * 2 + 2, loc, val));
	}
	return seg[idx];
}

int update2(int l, int r, int idx, int loc, int val)
{
	if (loc < l || loc > r) return seg2[idx];
	if (l == r) {
		if (l == loc) seg2[idx] = val;
	}
	else {
		int mid = (l + r) / 2;
		seg2[idx] = max(update2(l, mid, idx * 2 + 1, loc, val), update2(mid + 1, r, idx * 2 + 2, loc, val));
	}
	return seg2[idx];
}

int Min(int start, int end, int l, int r, int idx)
{
	if (r < start || l > end) return 100001;
	if (start <= l && r <= end) return seg[idx];
	int mid = (l + r) / 2;
	return min(Min(start, end, l, mid, idx * 2 + 1), Min(start, end, mid + 1, r, idx * 2 + 2));
}

int Max(int start, int end, int l, int r, int idx)
{
	if (r < start || l > end) return -1;
	if (start <= l && r <= end) return seg2[idx];
	int mid = (l + r) / 2;
	return max(Max(start, end, l, mid, idx * 2 + 1), Max(start, end, mid + 1, r, idx * 2 + 2));
}

int main()
{
	int t, n, k, q, a, b;
	cin >> t;
	while (t--)
	{
		scanf("%d%d", &n, &k);
		construct(0, n - 1, 0);
		construct2(0, n - 1, 0);
		for (int i = 0; i < k; i++) {
			scanf("%d%d%d", &q, &a, &b);
			if (q == 0) {
				int aLoc = Max(a, a, 0, n - 1, 0);
				int bLoc = Max(b, b, 0, n - 1, 0);
				update(0, n - 1, 0, a, bLoc);
				update2(0, n - 1, 0, a, bLoc);
				update(0, n - 1, 0, b, aLoc);
				update2(0, n - 1, 0, b, aLoc);
				aLoc = Max(a, a, 0, n - 1, 0);
				bLoc = Max(b, b, 0, n - 1, 0);
			}
			else {
				if (a == Min(a, b, 0, n - 1, 0) && b == Max(a, b, 0, n - 1, 0))
					printf("YES\n");
				else printf("NO\n");
			}
		}	
	}

	return 0;
}