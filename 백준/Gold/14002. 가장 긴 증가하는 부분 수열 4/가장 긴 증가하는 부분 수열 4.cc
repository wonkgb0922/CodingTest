#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ary[1001], dp[1001];

int main()
{
	int r = 1, ri = 0;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", ary + i);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ary[j] < ary[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (r < dp[i]) {
					r = dp[i];
					ri = i;
				}
			}
		}
	}
	printf("%d\n", r);
	v.push_back(ary[ri]);
	for (int i = ri; i > 0;) {
		for (int j = i - 1; j >= 0; j--) {
			if (dp[j] == r - 1 && ary[j] < ary[i]) {
				i = j;
				r--;
				v.push_back(ary[j]);
				break;
			}
		}
		if (r == 1) break;
	}
	for (auto it = v.rbegin(); it < v.rend(); it++)
		printf("%d ", *it);

	return 0;
}