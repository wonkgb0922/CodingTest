#include <stdio.h>
#include <iostream>
using namespace std;

int n, pre[1000], in[1001];

void postOrder(int idx, int L, int R) {
	if (idx >= n) return;
	if (L >= R) return;
	bool l = false, r = false;
	for (int i = 0; i < n; i++) {
		if (in[pre[i]] >= L && in[pre[i]] < in[pre[idx]] && !l) {
			l = true;
			postOrder(i, L, in[pre[idx]]);
		}
		else if (in[pre[i]] > in[pre[idx]] && in[pre[i]] < R && !r) {
			r = true;
			postOrder(i, in[pre[idx]] + 1, R);
		}
	}
	printf("%d ", pre[idx]);
}
int main(void) {
	int t, in1;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", pre + i);
		for (int i = 0; i < n; i++) {
			scanf("%d", &in1);
			in[in1] = i + 1;
		}
		postOrder(0, 1, n + 1);
		printf("\n");
	}
	return 0;

}