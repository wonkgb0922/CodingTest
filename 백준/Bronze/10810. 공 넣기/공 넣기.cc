#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, in1, in2, in3;
	int ary[101] = { 0, };
	cin >> n >> m;

	while(m--) {
		cin >> in1 >> in2 >> in3;
		fill(ary + in1, ary + in2 + 1, in3);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ary[i]);
	return 0;
}