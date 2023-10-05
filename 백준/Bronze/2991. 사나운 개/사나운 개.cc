#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d, ary[3], res, r;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < 3; i++) {
		scanf("%d", ary + i);
		res = 0;
		r = ary[i] % (a + b);
		if (!r) {
			if (!((ary[i] / (a + b)) % 2)) res++;
		}
		else if (r <= a) res++;
		r = ary[i] % (c + d);
		if (!r) {
			if (!((ary[i] / (c + d)) % 2)) res++;
		}
		else if (r <= c) res++;
		printf("%d\n", res);
	}
	return 0;
}