#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int n, ary[250000], cnt = 0, a;
	cin >> n;
	scanf("%d", &ary[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &ary[i]);
		if (ary[i - 1] > ary[i]) {
			a = ceil(log2(ary[i - 1] / double(ary[i])));
			ary[i] *= pow(2, a);
			cnt += a;
		}
	}
	printf("%d", cnt);
}