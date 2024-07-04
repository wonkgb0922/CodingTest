#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 1000000

using namespace std;

int seg[4000000];

int update(int l, int r, int idx, int loc, int val)
{
	if (l > loc || r < loc) return seg[idx];
	if (l == r) {
		if (l == loc) seg[idx] += val;
	}
	else {
		int mid = (l + r) / 2;
		seg[idx] = update(l, mid, idx * 2 + 1, loc, val) + update(mid + 1, r, idx * 2 + 2, loc, val);
	}
	
	return seg[idx];
}

int kth(int l, int r, int idx, int k)
{
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (seg[idx * 2 + 1] >= k)
		return kth(l, mid, idx * 2 + 1, k);
	else
		return kth(mid + 1, r, idx * 2 + 2, k - seg[idx * 2 + 1]);
}

int main()
{
	int n, a, b, c;
	cin >> n;
	while (n--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			int loc = kth(0, N - 1, 0, b);
			printf("%d\n", loc + 1);
			update(0, N - 1, 0, loc, -1);
		}
		else {
			scanf("%d%d", &b, &c);
			update(0, N - 1, 0, b - 1, c);
        }
	}
	
	return 0;
}