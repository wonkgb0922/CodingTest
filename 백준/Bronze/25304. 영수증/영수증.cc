#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int tot, n, in1, in2, sum = 0;
	cin >> tot;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in1 >> in2;
		sum += in1 * in2;
	}
	if (tot == sum) printf("Yes");
	else printf("No");
	return 0;
}