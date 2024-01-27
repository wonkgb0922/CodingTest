#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

string S, ary[101];
int n, dp[101];

bool word(int k)
{
	if (k == S.length()) return true;
	int& res = dp[k];

	if (res != -1) return res;
	res = 0;

	for (int i = 0; i < n; i++) {
		if (S.length() < ary[i].length() + k) continue;
		if (S.find(ary[i], k) == k)
			res = res || word(k + ary[i].length());
	}
	return res;
}

int main(void) {

	cin >> S;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	memset(dp, -1, sizeof(dp));

	cout << word(0);
	return 0;
}