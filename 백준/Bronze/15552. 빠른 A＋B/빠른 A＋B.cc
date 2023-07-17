#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, in1,in2;
	cin >> n;
	while (n--) {
		scanf("%d %d", &in1, &in2);
		printf("%d\n", in1 + in2);
	}
	return 0;
}