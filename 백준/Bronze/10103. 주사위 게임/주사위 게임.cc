#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, in1, in2;
	int score[2] = { 100, 100};
	cin >> n;
	while (n--) {
		cin >> in1 >> in2;
		if (in1 > in2) score[1] -= in1;
		else if (in1 < in2) score[0] -= in2;
	}
	printf("%d\n%d", score[0], score[1]);
	return 0;
}