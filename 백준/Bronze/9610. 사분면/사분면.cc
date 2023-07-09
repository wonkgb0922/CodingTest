#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ary[4] = {0, }, axis = 0, n, in1, in2;
	cin >> n;
	while (n--) {
		cin >> in1 >> in2;
		if (!in1 || !in2) {
			axis++;
			continue;
		}
		if (in1 > 0) {
			(in2 > 0) ? ary[0]++ : ary[3]++;
		}
		else {
			(in2 > 0) ? ary[1]++ : ary[2]++;
		}
	}
	for (int i = 0; i < 4; i++) {
		printf("Q%d: %d\n", i + 1, ary[i]);
	}
	printf("AXIS: %d", axis);

	return 0;
}