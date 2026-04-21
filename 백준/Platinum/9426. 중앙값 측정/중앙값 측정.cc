#include <iostream>
#include <stdlib.h>
#define MAX 65536

using namespace std;

struct Node {
	int cnt = 0;
	int val = 0;
	Node() {}
};

Node segMax[MAX * 2];
Node segMin[MAX * 2];
int n, k;

void updateMax(int idx, int val) {
	int i = idx + MAX;
	segMax[i].cnt += val;
	if(segMax[i].cnt > 0)
		segMax[i].val = idx;
	else
		segMax[i].val = 0;
	i >>= 1;
	while (i) {
		segMax[i].cnt = segMax[i << 1].cnt + segMax[i << 1 | 1].cnt;
		segMax[i].val = max(segMax[i << 1].val, segMax[i << 1 | 1].val);
		i >>= 1;
	}
}

void updateMin(int idx, int val) {
	int i = idx + MAX;
	segMin[i].cnt += val;
	if (segMin[i].cnt > 0)
		segMin[i].val = idx;
	else
		segMin[i].val = MAX;
	i >>= 1;
	while (i) {
		segMin[i].cnt = segMin[i << 1].cnt + segMin[i << 1 | 1].cnt;
		segMin[i].val = min(segMin[i << 1].val, segMin[i << 1 | 1].val);
		i >>= 1;
	}
}

void add(int val) {
	if (segMax[1].val < val) {
		updateMin(val, 1);
	}
	else
		updateMax(val, 1);
}

void remove(int val) {
	if (segMax[1].val < val) {
		updateMin(val, -1);
	}
	else
		updateMax(val, -1);
}

void balance() {
	while (segMax[1].cnt < segMin[1].cnt) {
		updateMax(segMin[1].val, 1);
		updateMin(segMin[1].val, -1);
	}
	while (segMax[1].cnt > segMin[1].cnt + 1) {
		updateMin(segMax[1].val, 1);
		updateMax(segMax[1].val, -1);
	}
}

int ary[250000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	long long res = 0;
	int i;
	for (i = 1; i < MAX * 2; i++)
		segMin[i].val = MAX;
	for (i = 0; i < k; i++) {
		cin >> ary[i];
		add(ary[i]);
		balance();
	}
	res += segMax[1].val;
	for (; i < n; i++) {
		remove(ary[i - k]);
		cin >> ary[i];
		add(ary[i]);
		balance();
		res += segMax[1].val;
	}
	cout << res;
	return 0;
}