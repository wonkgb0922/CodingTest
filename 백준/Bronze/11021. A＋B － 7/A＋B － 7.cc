#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, in1,in2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &in1, &in2);
		printf("Case #%d: %d\n", i, in1 + in2);
	}
	return 0;
}