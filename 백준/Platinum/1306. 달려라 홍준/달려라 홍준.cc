#include <iostream>
#include <stdlib.h>
#define MAX 1000000

using namespace std;

int seg[MAX * 2];
int n, m;

void add(int idx, int val) {
	idx += n;
	seg[idx] = val;
	idx >>= 1;
	while (idx) {
		seg[idx] = max(seg[idx << 1], seg[idx << 1 | 1]);
		idx >>= 1;
	}
}

int query(int l, int r) {
	int ret = 0;
	l += n; r += n;
	while (l <= r) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (!(r & 1)) ret = max(ret, seg[r--]);
		l >>= 1; r >>= 1;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		add(i, in);
	}
	m--;
	for (int l = m; l < n - m; l++)
		cout << query(l - m, l + m) << " ";
	
	return 0;
}