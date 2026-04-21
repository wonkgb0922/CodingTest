#include <iostream>
#include <algorithm>
#define MAX 1000000

using namespace std;

int n;
int t[MAX * 4];
int ary[1000001];

int set(int p, int tl, int tr, int idx, int val) {
	if (tl + 1 == tr) {
		if (tl == idx)
			t[p] = val;
		return t[p];
	}
	int mid = (tl + tr) >> 1;
	if (idx < mid)
		t[p] = set(p << 1, tl, mid, idx, val) + t[p << 1 | 1];
	else
		t[p] = t[p << 1] + set(p << 1 | 1, mid, tr, idx, val);
	return t[p];
}

int query(int p, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l) return 0;
	if (l <= tl && tr <= r) return t[p];
	int mid = (tl + tr) >> 1;
	return query(p << 1, tl, mid, l, r) + query(p << 1 | 1, mid, tr, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		ary[in] = i;
		set(1, 0, n, i, 1);
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		cin >> in;
		res += query(1, 0, n, 0, ary[in]);
		set(1, 0, n, ary[in], 0);
	}
	cout << res;
	return 0;
}