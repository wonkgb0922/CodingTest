#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if ((m == 0 || k == 0) && m + k == n) printf("0");
	else printf("%d", min(m, k) + n - max(m, k));
	return 0;
}