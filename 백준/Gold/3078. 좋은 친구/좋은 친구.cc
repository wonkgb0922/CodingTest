#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, k, len;
	long long cnt = 0;
	string in;
	queue<int> q[21];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> in;
		len = in.length();
		while (!q[len].empty() && ((i - q[len].front()) > k)) q[len].pop();
		cnt += q[len].size();
		q[len].push(i);
	}
	printf("%lld", cnt);
	return 0;
}